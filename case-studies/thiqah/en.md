# THIQAH — documenting business-to-business relationships

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

A B2B trade-network project with identity, organisation and authorisation foundations, working towards documented invoices, receivables, payments and disputes.

**Stage: In development**

![THIQAH — documenting business-to-business relationships](https://yahyaalali.com/images/editorial/thiqah-network-r3.webp)

Generated conceptual illustration, not an actual interface or research result.

## A shared record of the business relationship

THIQAH is a project for documenting relationships between businesses, providing a context in which invoices, receivables, payments and disputes can be traced. It is not designed as a public marketplace or financial wallet; its purpose is to organise the information behind a business relationship.

## The current foundation

I have developed the multilingual Flutter presentation foundation and responsive interface, alongside backend foundations for identity, organisations, authorisation and an audit trail. These provide defined account and organisation boundaries for subsequent business features.

Invoices, receivables, payments and disputes remain on the development roadmap rather than complete commercial functions. The project does not hold customer funds; any future payment integration requires an appropriate separate arrangement.

The current core covers identity, sessions, organizations, memberships, branches and scoped authorization. The invitation workflow is unconfirmed. Invoices, receivables, settlements, disputes and commercial synchronization remain designed or incomplete, with no end-to-end verification. Administrative audit records concern selected administrative operations; commercial accounting is a separate domain.

## Engineering priorities

The work separates a coherent user experience from the implementation of financial operations. PostgreSQL and Prisma support durable data, while Flutter and Dart provide the interface. Current development prioritises identity, relationships and permissions before extending the business domains.

## At a glance

- **Problem:** Organising the information and history behind relationships between businesses.
- **Audience:** Businesses that need records of their relationships, invoices and receivables.
- **My role:** Presentation, identity, organisations, authorisation and data foundations.
- **Technologies and method:** Flutter, Dart, PostgreSQL, Prisma
- **Available to review:** A multilingual interface foundation and identity/organisation/audit services, with commercial-domain features on the subsequent roadmap.

## Implemented foundation and commercial design

I designed the shared trade-record model and developed the current foundation: a multilingual Flutter shell and a NestJS modular monolith using PostgreSQL and Prisma. The documented core handles identity, sessions, organizations, memberships, branches and scoped authorization. Selected administrative operations have audit records and limited idempotency. Invoices, receivables, reconciliation, objections and commercial offline synchronization are designed or incomplete; their end-to-end operation is unconfirmed. A queued device action is distinct from a server-confirmed transaction or counterparty acceptance.

[Continue reading on the website](https://yahyaalali.com/en/works/thiqah/) · [Back to selected work](../../README.md)
