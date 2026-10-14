# Academic Portfolio — from content to a reading experience

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

A trilingual platform I developed to present my academic and engineering work and manage articles, case studies and a Dart book in a private, owner-only editorial workspace that separates drafts from publication.

**Stage: Published**

![Academic Portfolio — from content to a reading experience](https://yahyaalali.com/images/editorial/portfolio-editorial-r3.webp)

Generated conceptual illustration, not an actual interface or research result.

## Research, engineering and knowledge in one platform

![Platform identity: research, engineering and knowledge](../../assets/editorial/platform-identity-r4.webp)

The generated conceptual opening represents the whole platform, not a single product screenshot or evidence of research results. Titles and actions remain live text in the selected language.

I built this platform to present academic work, software projects and technical writing with a clear account of the problem, my contribution and the material readers can actually explore. The interface supports Arabic, English and Turkish and handles their different reading directions.

## Editing and publication

The administration workspace is private to the site owner; visitors cannot enter it. It supports personal information, case studies and articles, with translations linked to their source. Each edit is saved as an independent draft with revision history and a preview before publication. Saving does not make content public; an earlier revision can be restored as a draft without silently replacing the published version.

## A book designed for reading

The book reader provides a unit and topic index, code examples, tables, equations and questions connected to their solutions. Educational material is managed as structured blocks rather than separate page files, while unpublished units remain outside visitor access.

## Engineering decisions

I used Astro and TypeScript for the interface and Firebase services for hosting, content storage and backend execution. The content model connects a record to its language, revision and publication state. Route and access tests help verify the separation between public reading and the owner workspace.

The platform continues to evolve through coherent releases reviewed on its domain, without waiting for every educational unit to be complete or disclosing private project source code.

## At a glance

- **Problem:** Present research, software projects and educational writing together while keeping material under review separate from public content.
- **Audience:** Readers, students, colleagues and prospective academic and engineering collaborators
- **My role:** Platform design, interface and backend development, and content management
- **Technologies and method:** Astro, TypeScript, Firebase Hosting, Cloud Functions, Firestore
- **Engineering decision:** Separate draft saving from publication through structured content and retained revisions, with shared language routing and text-direction rules.
- **Available to visitors:** The live site, Arabic/English/Turkish navigation and the reader for published book material, with its topics, questions and available solutions. The content editor and draft previews are owner-only.

[Continue reading on the website](https://yahyaalali.com/en/content-library/project/academic-portfolio/) · [Visit the website](https://yahyaalali.com/en/) · [Back to selected work](../../README.md)
