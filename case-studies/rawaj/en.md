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

This structure separates the user experience, business logic, data and real-time communication. The current foundation covers account-profile management, access control and administrative audit, while order, return, dispute and settlement flows are being developed incrementally.

## Current stage

Rawaj remains in development and is not operating commercially. The next work focuses on completing the marketplace flows and connecting them to a coherent interface, with clear seller, buyer and administrator responsibilities.

## At a glance

- **Problem:** Connecting marketplace participants with order state and after-sales workflows.
- **Audience:** Sellers, buyers and marketplace administrators.
- **My role:** Application design, interface, backend services and data model.
- **Technologies and method:** Flutter, Dart, TypeScript, Node.js, Express, PostgreSQL, Redis, Socket.IO
- **Available to review:** Account-profile, access-control and administrative-audit foundations; order, return, dispute and settlement flows remain in development.

[Continue reading on the website](https://yahyaalali.com/en/content-library/project/rawaj/) · [Back to selected work](../../README.md)
