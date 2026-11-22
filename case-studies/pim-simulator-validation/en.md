# PIM simulator validation — uPIMulator and Downmem

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

**Independent research in progress**

This study develops a validation protocol for a common UPMEM vector-addition workload in uPIMulator and Downmem. It asks whether each simulator produces the expected output and what operations its logs describe.

## Verification protocol

Fix the workload, input data and simulator settings. Compute the expected vector independently, extract the simulator output and compare element by element. The planned matrix has six runs: baseline, swapped operands A and B, and reversed element order in both inputs in each simulator. For the reversal case, restore the original element order before comparison.

## Correctness and performance

Matching outputs establish correctness only for the checked cases. The selected uPIMulator verification read and the Downmem adapter readback cover different operations. Compare log semantics and measurement boundaries before interpreting counters or timing.

## Evidence and limits

The protocol and selected execution paths are documented. The six comparison runs remain pending in the published study, and controlled error-detection tests are planned. Performance equivalence, measured system energy and general simulator agreement have not been established.

[Read the published study](https://yahyaalali.com/en/research/studies/gem5-pim/) · [Historical gem5 coursework audit](../gem5-pim/en.md) · [Back to selected work](../../README.md)
