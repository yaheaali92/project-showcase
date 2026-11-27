# Dr. Omar Ali Al-Najras Clinic

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

[Published case study](https://yahyaalali.com/en/works/omar-clinic/)

Digital Health / 2026

A connected digital experience for clinic management and patient follow-up on the web and Android.

- **Platforms:** A website and Android app sharing one codebase
- **Languages:** Arabic · Turkish · English
- **Availability:** Live web portal and Google Play app listing

A digital solution designed to bring Dr. Omar Ali Al-Najras Clinic together across web and mobile in a smooth trilingual experience. It combines a dedicated patient space for appointments and visits with a connected workspace for the doctor and clinic administration to organize schedules, clinical records, and daily operations.

[View the interface and diagrams in the case study](https://yahyaalali.com/en/works/omar-clinic/)

Illustrative preview based on the application interfaces

## Vision and Digital Clinic Experience

A modern medical clinic needs more than a static brochure page; it needs a clear digital channel that organizes appointment requests and follow-up flows, keeps patients connected with their doctor, and allows clinic administration to manage schedules and records through connected interfaces.

This solution was built to organize those needs within a dedicated application for Dr. Omar Ali Al-Najras Clinic, uniting its web presence and Android app on a shared codebase structured for expansion to additional platforms, with native support for Arabic, Turkish, and English from the very first screen. The project is tailored specifically to Dr. Omar's clinic and remains independent in scope and architecture from SINAD, a separate platform for multi-practice clinic management.

### Visual Identity

The tooth identifies the clinic’s dental specialty; the medical cross and check motif suggest care and follow-up. The doctor’s name connects these visual cues to the clinic, using the turquoise seen in its interfaces.

### Visual identity meaning

## Inside the Application Interfaces

This gallery presents five parts of the clinic experience. Each image is labelled either as a capture of actual app components using synthetic demo data or as an illustrative preview reconstructed from the source.

[View the interface and diagrams in the case study](https://yahyaalali.com/en/works/omar-clinic/#omar-section-2)

Illustrative preview based on the application interfaces

### Multilingual Sign-In Gateway

A streamlined entry point in Arabic, Turkish, and English featuring sign-in, account registration, password recovery, and direct clinic contact links.

[View the interface and diagrams in the case study](https://yahyaalali.com/en/works/omar-clinic/#omar-section-2)

Illustrative preview based on the application interfaces

### Patient Workspace and Appointments

A clean interface allowing patients to browse available times based on clinic branches and schedules, and submit, cancel, or reschedule appointment requests.

[View the interface and diagrams in the case study](https://yahyaalali.com/en/works/omar-clinic/#omar-section-2)

Illustrative preview based on the application interfaces

### Doctor Dashboard and Daily Schedule

A central workspace bringing incoming appointment requests and statuses together, making it easy to organize the clinic day and jump directly into patient records.

[View the interface and diagrams in the case study](https://yahyaalali.com/en/works/omar-clinic/#omar-section-2)

Actual dental component with demo data in an isolated harness

### Patient Profile and Interactive Dental Chart

A structured view of visits and clinical images paired with an interactive dental chart for selecting teeth in the context of a visit.

[View the interface and diagrams in the case study](https://yahyaalali.com/en/works/omar-clinic/#omar-section-2)

Illustrative preview based on the application interfaces

### Clinic Management, Reports, and Content

Dedicated tools for financial reports, branch and working-hour configuration, service catalogs, clinic news, and the achievements gallery.

## How the Solution Serves Patients and the Clinic

Capabilities are organized around both sides of the clinic experience so every user reaches their tools directly:

### Patient Experience

1. Submitting appointment requests, tracking request status, requesting cancellations or rescheduling, and supporting family visits
   .
2. Notification flows and Android local pre-appointment reminder pathways
   .
3. A personal profile presenting visit history and permitted clinical images alongside doctor details, clinic news, and achievements
   .

### Clinician and Administration Experience

1. Management of patient records, visits, clinical images, and the interactive dental chart
   .
2. Configuration of branches, working schedules, and service catalogs, paired with clinic financial reporting
   .
3. In-app management of doctor information, social links, clinic announcements, and the achievements gallery
   .

## Appointment Journey and System Architecture

The workflow pairs a straightforward user experience with a direct technical structure, avoiding unnecessary intermediate layers.

Request journey

### Figure 01 — Appointment Request Journey

1. 01
   **Schedule:**
   Reading clinic working hours, branches, and existing appointments.
2. 02
   **Time Slot:**
   Selecting a period according to the schedules and bookings handled by the app.
3. 03
   **Request:**
   Composing and submitting an individual or family appointment request.
4. 04
   **Pending:**
   Pending
   Recording the request with a pending status alongside a clinician notification path.
5. 05
   **Follow-Up:**
   Supporting cancellation and rescheduling paths, plus the Android-only local reminder pathway.

After submitting the request

- Cancellation
- Rescheduling

On-device Android reminder

System map

### Figure 02 — Digital System Architecture

1. **Interface Layer:**
   Web
   Android
   Shared Flutter codebase
2. **Application Core:**
   Patient screens
   Clinician screens
   Data models
   Language management
   Appointment coordination
3. Application interfaces connect directly to cloud services
   **Cloud services**
   Authentication and user accounts
   Firebase Authentication
   Records, appointments and settings
   Cloud Firestore
   Clinical image storage
   Cloud Storage
   **Supporting capabilities vary by platform**

- App notifications
  Firebase Cloud Messaging
- Usage analytics
  Firebase Analytics
- Crash reporting on native platforms
  Firebase Crashlytics
- On-device Android reminder

## Technology, Contribution, and Links

### Tools and Technologies

#### Interface and Cross-Platform:

`Flutter` · `Material 3` · Trilingual `ARB` localization · `LanguageCubit`.

#### Accounts and Data:

`Firebase Authentication` · `Cloud Firestore` · `Cloud Storage` · `AppointmentController`.

#### Alerts and Monitoring:

`Firebase Cloud Messaging` · Android local reminders · `Analytics` · `Crashlytics`.

### My Contribution

I designed and developed the clinic's web and mobile solution on a unified `Flutter` codebase—building the trilingual patient and clinician interfaces, appointment and visit workflows, interactive dental chart, administrative modules, `Firebase` integration, live web deployment, and Google Play app listing.

### Public Access and Scope

The published trilingual web entry point is available online, and the Android app is listed on Google Play. Descriptions and interface previews of protected patient and clinician journeys are drawn from the application's source code using synthetic demo data to safeguard patient privacy and clinic accounts.

### Project Links

### Project links

- [Visit Website](https://alnajrasclinic.com/)
- [Android App](https://play.google.com/store/apps/details?id=com.yahyaalali.dental_clinic_app)
- [Published case study](https://yahyaalali.com/en/works/omar-clinic/)

[Back to projects](../../README.md)
