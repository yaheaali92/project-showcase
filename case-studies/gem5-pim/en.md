# gem5 course study: provenance audit of two memory profiles

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md) · [Portfolio](https://yahyaalali.com/en/)

The study began as computer-architecture coursework. In October 2026 I reviewed available artifacts for seven workloads: Dhrystone, a Google-inspired workload, matrix multiplication, PageRank, a STREAM-like workload, a tiny CNN and vector addition. Each has available C source, an executable and a historical pair of gem5 statistics labelled baseline and PIM. File fingerprints are retained privately; source code, executables and raw statistics are not published here.

## Evidence limits

The bounded materials did not contain run commands, the exact gem5 version, configurations, exit codes or matching functional outputs. File presence alone does not prove that the executable came from the available source or ran on both sides. The old report's matrix size differs from the available source; aggregate CSV IPC/CPI figures do not match the paired statistics. The historical CSV extractor was not found in scope, so the cause is unknown.

The old report describes different memory profiles, but the inspected materials do not establish an in-memory compute unit or computational offload. The PIM label does not prove a particular implementation. The STREAM-like application's timer is synthetic rather than a real elapsed-time measurement.

## Audit result

A new independent auditor read 14 statistics files and passed nine focused tests. No pair qualified for a performance ratio because equal work, matching outputs and successful exits were not established. The simulation was not rerun in 2026, and system energy was not measured through a documented model. This is a course study and provenance audit, not a peer-reviewed paper or architectural superiority claim.

A new experiment requires a pinned gem5 version, configurations and commands for both sides, program/input fingerprints and matching functional outputs before comparing metrics.
