#ifndef SMART_BIN_DECLARATION_STUB_BLE
#define SMART_BIN_DECLARATION_STUB_BLE
#include "Arduino.h"
class BLECharacteristic;
class BLECharacteristicCallbacks {
 public:
  virtual ~BLECharacteristicCallbacks() = default;
  virtual void onRead(BLECharacteristic*) {}
  virtual void onWrite(BLECharacteristic*) {}
};
class BLEServer;
class BLEServerCallbacks {
 public:
  virtual ~BLEServerCallbacks() = default;
  virtual void onConnect(BLEServer*) {}
  virtual void onDisconnect(BLEServer*) {}
};
class BLE2902 {};
class BLECharacteristic {
 public:
  static constexpr std::uint32_t PROPERTY_READ = 1, PROPERTY_WRITE = 2, PROPERTY_NOTIFY = 4, PROPERTY_INDICATE = 8;
  String getValue() const;
  std::size_t getLength() const;
  void setValue(const String&);
  void notify(bool = true);
  void setCallbacks(BLECharacteristicCallbacks*);
  void addDescriptor(BLE2902*);
};
class BLEService {
 public: BLECharacteristic* createCharacteristic(const char*, std::uint32_t); void start();
};
class BLEServer {
 public:
  std::uint32_t getConnectedCount();
  void setCallbacks(BLEServerCallbacks*);
  BLEService* createService(const char*);
  void startAdvertising();
};
class BLEAdvertising { public: void addServiceUUID(const char*); void setScanResponse(bool); };
class BLEDevice { public: static void init(const char*); static BLEServer* createServer(); static BLEAdvertising* getAdvertising(); static void startAdvertising(); };
#endif
