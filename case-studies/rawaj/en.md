# Rawaj — engineering a digital marketplace

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

A multi-role marketplace project connecting sellers, buyers and platform administration, with separate interface, business-service and data responsibilities.

**Stage: In development**

![Rawaj — engineering a digital marketplace](https://yahyaalali.com/images/editorial/rawaj-journey-r3.webp)

Generated conceptual illustration, not an actual interface or research result.

## Bringing the marketplace participants together

I began developing Rawaj in 2026 as a digital marketplace for sellers, buyers and platform administration. The project extends beyond product listings to the journey of an order and the handling of returns, disputes and settlements after a sale.

My work covers application design, the interface, backend services and the data model. A practical question guides development: how can each action remain clear to its user and consistent with the order state and account permissions?

Product presentation connects the seller and buyer; an order then opens a sequence with different responsibilities for both parties and platform administration. The scope covers order state, return requests, disputes and settlements under the relevant permissions. These journeys are developed and connected to the application progressively; their description does not imply a completed commercial launch.

## Separate engineering responsibilities

| Layer | Technology and purpose |
| --- | --- |
| Application interface | Flutter and Dart |
| Application services | TypeScript, Node.js and Express |
| Durable data | PostgreSQL |
| Caching | Redis |
| Real-time communication | Socket.IO |

This architecture separates the user experience, business logic, data, and real-time communication. The codebase includes account and permission management, administrative action logging, listing publication and moderation, cart and order workflows, and components for returns, disputes, and accounting for amounts owed to sellers. The extent of integration and verification varies across these workflows; their presence in the code does not establish acceptance of an end-to-end commercial journey.

The Flutter interface presents actions according to account permissions and order, payment, and return states, while backend services check authorization and validate state transitions. In this project, settlements refer to recording amounts owed to sellers and linking them to orders and ledger entries; actual payouts are a separate stage.

## Current stage

Rawaj remains in development and has not entered commercial operation. Earlier, separate local test rounds documented listing publication, moderation, and cart workflows through interfaces connected to the backend and database, using synthetic data.

Recorded checks on 26 October 2026 covered logging in and viewing buyer orders and financial data through Flutter interfaces connected to the backend and database, on the web and an Android emulator, using synthetic data. The financial operations accepted in that round were read-only.

The complete order and after-sales journey, including returns and disputes between the parties, still requires end-to-end acceptance. Payment collection, refunds, and seller payouts through an approved provider remain to be verified, and commercial operation has not begun.

## At a glance

- **Problem:** Connecting marketplace participants with order state and after-sales workflows.
- **Audience:** Sellers, buyers and marketplace administrators.
- **My role:** Application design, interface, backend services and data model.
- **Technologies and method:** Flutter, Dart, TypeScript, Node.js, Express, PostgreSQL, Redis, Socket.IO
- **Available to review:** A summary of the architecture, implementation scope, and documented local verification rounds and their limits. The project's private source code and internal acceptance records are not included in this case study.

## Order boundaries and verification

I designed and developed the buyer, seller and moderation workflows. Flutter/Dart handles the interface, Express/TypeScript the guarded services, and PostgreSQL the transactional records. Order state separates transaction, logistics, payment and return. A return can open a linked dispute; seller settlement in the ledger records an entitlement and can be put on hold. Selected flows were verified separately on local web, Android emulator and Windows with synthetic data. Live collection, refunds, provider reconciliation and payouts remain outside the verified scope.

[Continue reading on the website](https://yahyaalali.com/en/works/rawaj/) · [Back to selected work](../../README.md)
