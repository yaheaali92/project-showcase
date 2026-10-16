// Original sketch attribution: E.YAHYA ALALI / نسبة الأصل: يحيى علي / Özgün kaynak: E.YAHYA ALALI.
#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <atomic>
#include "src/bin_core.h"
#include "src/i18n.h"
#include "src/oled_labels.h"
#include "src/pin_config.h"

#ifndef SMART_BIN_LANGUAGE
#define SMART_BIN_LANGUAGE 0
#endif
static_assert(SMART_BIN_LANGUAGE >= 0 && SMART_BIN_LANGUAGE <= 2, "Language must be ar=0, en=1, tr=2");
constexpr smartbin::Language language = static_cast<smartbin::Language>(SMART_BIN_LANGUAGE);
constexpr int triggerPin = smartbin::pins::trigger;
constexpr int echoPin = smartbin::pins::echo;
constexpr int buzzerPin = smartbin::pins::buzzer;
constexpr int powerLedPin = smartbin::pins::powerIndicator;
constexpr auto& ledPins = smartbin::pins::fillIndicators;
constexpr char serviceUuid[] = "4fafc201-1fb5-459e-8fcc-c5c9c331914b";
constexpr char characteristicUuid[] = "beb5483e-36e1-4688-b7f5-ea07361b26a8";
constexpr std::uint32_t triggerLowUs = 2, triggerHighUs = 10, idleSliceMs = 1;
smartbin::Config config;
Adafruit_SSD1306 display(128, 64, &Wire, -1);
BLEServer* server = nullptr;
BLECharacteristic* characteristic = nullptr;
std::atomic<bool> bleConnected{false}, advertisingRequested{false};
portMUX_TYPE snapshotMux = portMUX_INITIALIZER_UNLOCKED;
smartbin::Snapshot publishedSnapshot;

smartbin::Snapshot readSnapshot() {
  portENTER_CRITICAL(&snapshotMux);
  auto result = publishedSnapshot;
  portEXIT_CRITICAL(&snapshotMux);
  return smartbin::currentSnapshot(result, millis(), config);
}
void restoreReadValue(BLECharacteristic* value) {
  value->setValue(String(smartbin::wireValue(readSnapshot().state)));
}
class ServerCallbacks final : public BLEServerCallbacks {
  void onConnect(BLEServer*) override {
    bleConnected.store(true);
    BLEDevice::startAdvertising();
  }
  void onDisconnect(BLEServer* value) override {
    const bool remaining = value->getConnectedCount() > 0;
    bleConnected.store(remaining);
    if (!remaining) advertisingRequested.store(true);
  }
};
class CharacteristicCallbacks final : public BLECharacteristicCallbacks {
  void onRead(BLECharacteristic* value) override { restoreReadValue(value); }
  void onWrite(BLECharacteristic* value) override {
    const std::size_t length = value->getLength();
    // EN: Bound length before getValue; never log the received bytes.
    // AR: افحص الحجم قبل getValue؛ لا تسجل محتوى المدخل.
    // TR: getValue öncesi boyutu sınırla; gelen baytları kaydetme.
    smartbin::WriteResult result;
    if (length > config.maximumWriteBytes) result = smartbin::WriteResult::TooLong;
    else {
      const String input = value->getValue();
      result = smartbin::inspectWrite(input.c_str(), input.length(), config);
    }
    restoreReadValue(value);
    Serial.println(smartbin::writeResultLabel(language, result));
  }
};
class Esp32Io final : public smartbin::DeviceIo {
  bool initializeDisplay() override {
    const bool ready = display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    if (!ready) Serial.println(smartbin::displayFailureLabel(language));
    return ready;
  }
  std::uint32_t measureEcho(std::uint32_t timeoutUs) override {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(triggerLowUs);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(triggerHighUs);
    digitalWrite(triggerPin, LOW);
    return pulseIn(echoPin, HIGH, timeoutUs);
  }
  bool connected() const override { return bleConnected.load(); }
  bool consumeAdvertisingRequest() override { return advertisingRequested.exchange(false); }
  void advertise() override { server->startAdvertising(); }
  void outputs(unsigned leds, bool buzzer) override {
    for (unsigned i = 0; i < 4; ++i) digitalWrite(ledPins[i], i < leds ? HIGH : LOW);
    digitalWrite(buzzerPin, buzzer ? HIGH : LOW);
  }
  void render(const smartbin::Snapshot& snapshot) override {
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.drawBitmap(4, 2, smartbin::oledStateLabel(language, snapshot.state), 120, 20, SSD1306_WHITE);
    display.setTextSize(2);
    display.setCursor(8, 30);
    if (snapshot.valid) {
      display.print(snapshot.distanceCm, 1);
      display.drawBitmap(82, 32, smartbin::oledUnitLabel(language), 28, 20, SSD1306_WHITE);
    }
    else display.print("--");
    display.display();
  }
  void publish(const smartbin::Snapshot& snapshot) override {
    portENTER_CRITICAL(&snapshotMux);
    publishedSnapshot = snapshot;
    portEXIT_CRITICAL(&snapshotMux);
    restoreReadValue(characteristic);
  }
  void notifyFull() override {
    restoreReadValue(characteristic);
    characteristic->notify();
  }
};
Esp32Io io;
smartbin::Controller controller(io, config);
void setup() {
  Serial.begin(115200);
  Wire.begin(smartbin::pins::oledSda, smartbin::pins::oledScl);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(powerLedPin, OUTPUT);
  digitalWrite(powerLedPin, HIGH);
  for (int pin : ledPins) { pinMode(pin, OUTPUT); digitalWrite(pin, LOW); }
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  BLEDevice::init("E.YAHYA ALALI");
  server = BLEDevice::createServer();
  server->setCallbacks(new ServerCallbacks());
  BLEService* service = server->createService(serviceUuid);
  characteristic = service->createCharacteristic(characteristicUuid,
    BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE |
    BLECharacteristic::PROPERTY_NOTIFY | BLECharacteristic::PROPERTY_INDICATE);
  characteristic->setCallbacks(new CharacteristicCallbacks());
  characteristic->addDescriptor(new BLE2902());
  service->start();
  auto* advertising = BLEDevice::getAdvertising();
  advertising->addServiceUUID(serviceUuid);
  advertising->setScanResponse(false);
  controller.begin(millis());
  BLEDevice::startAdvertising();
}
void loop() {
  controller.tick(millis());
  // A bounded scheduler slice avoids a busy spin without multi-second blocking.
  delay(idleSliceMs);
}
