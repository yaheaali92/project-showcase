# Sinad — organising a doctor's practice and patient appointments

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

A role-based application connecting the doctor's workspace and patient appointment journeys, built with Flutter and Firebase and offered through a separate test preview.

**Stage: Test preview**

![Sinad — organising a doctor's practice and patient appointments](https://yahyaalali.com/images/editorial/sinad-workflow-r3.webp)

Generated conceptual illustration, not an actual interface or research result.

## Linking appointments with practice organisation

I am developing Sinad to connect the doctor's working schedule with the patient's appointment journey. The interface separates roles: the doctor's workspace supports schedule management, while the patient follows the associated booking process.

Flutter and Dart provide the interface, with Firebase supporting identity, data and backend services. My work connects interface actions to data state and permissions so that an appointment forms part of a coherent workflow rather than an isolated form.

The practice belongs to the doctor; a centre or clinic is a work location in that doctor's schedule. Two doctors at the same centre have separate practice spaces: sharing a location does not automatically share patient records. The patient's booking journey connects the doctor, service, location and available time. These journeys continue to be implemented and tested in a preview environment before operational release.

## What the preview offers

The [Sinad test environment](https://test.sinaddental.com/) exposes the sign-in interface and the functions available to test accounts. It is a testing environment, not clinical operation with real patient data; operational release remains separate from this project preview.

## At a glance

- **Problem:** Connecting the doctor's schedule with a clear patient booking journey.
- **Audience:** Doctors and patients with distinct roles and workspaces.
- **My role:** Application interface and integration of identity, data and booking services.
- **Technologies and method:** Flutter, Dart, Firebase
- **Available to review:** A separate web test interface available through an explicitly labelled preview domain.

[Continue reading on the website](https://yahyaalali.com/en/content-library/project/dental/) · [Open the test-environment sign-in](https://test.sinaddental.com/) · [Back to selected work](../../README.md)
