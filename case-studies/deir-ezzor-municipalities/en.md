# Municipal administration — connected levels of work

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

A platform for municipal activities, projects, tasks, tickets and reports, being extended from Deir Ezzor to a Syria–governorate–municipality structure.

**Stage: In development**

![Municipal administration — connected levels of work](https://yahyaalali.com/images/editorial/municipalities-hierarchy-r3.webp)

Generated conceptual illustration, not an actual interface or research result.

## Organising municipal work

The platform began as a way to organise Deir Ezzor municipal activities, projects, tasks, support requests and reports. Each operation is associated with its municipality so that staff can follow responsibilities and progress without searching through disconnected files and procedures.

In the early phase, I developed the Flutter interface and data model, integrating the backend with PocketBase and JavaScript. That phase covered the municipal workflows described above. Permission and data boundaries remain under review as the platform develops.

## A wider structure in development

The platform is being extended to a clear hierarchy: Syria, its governorates and their municipalities. Each level presents the work and permissions appropriate to it, with records associated with the relevant governorate and municipality. This requires revisiting relationships and responsibilities, not simply adding governorate names to a list.

This is the current development direction, not a completed national operation or a claim of government-wide endorsement. The platform is separate from the [Ashara portal](https://yahyaalali.com/en/content-library/project/ashara/): Ashara presents city information and services, while this platform organises municipal administrative work.

## Demonstration availability

The previous preview is temporarily paused during development and expansion. The accompanying diagram illustrates the intended work structure; it is not a live government dashboard or operational data.

## At a glance

- **Problem:** Connecting municipal procedures to the relevant municipality and permission scope.
- **Audience:** People managing municipal operations, projects and tasks.
- **My role:** Administration interface, data model and backend integration.
- **Technologies and method:** Flutter / Dart; C# / .NET 10; PostgreSQL. PocketBase / JavaScript belong to the historical implementation and staged transition.
- **Available to review:** An existing municipal-work application undergoing expansion to a multi-governorate hierarchy.

## Administrative scope and transition

I developed the platform to connect governorates, municipalities and departments through scoped responsibilities for projects, activities, assignments, evidence review and reports. The verified interface is Arabic. Isolated Flutter components and source-based illustrations use synthetic data. The service design uses a C#/.NET 10 modular monolith and PostgreSQL while retaining a PocketBase legacy path during transition. The demonstrations cover selected workflows; a complete migration, government endorsement and municipality-wide production operation are unconfirmed.

[Continue reading on the website](https://yahyaalali.com/en/works/deir-ezzor-municipalities/) · [Back to selected work](../../README.md)
