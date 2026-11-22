# Concurrent Samurai Sudoku

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

**Locally tested educational implementation**

## Design and implementation

The Java solver models five overlapping Sudoku grids as one board of 369 physical cells, including 36 shared cells. After validating the givens, synchronized workers each search the full board from an independent state, starting at distinct anchors and then choosing a most-constrained cell. Five workers use one anchor per grid; ten use two. The first valid result is published atomically, remaining work is cancelled and joined, and the winning board is checked again.

## Verification, limits and availability

The sequenced event log supports replay of one selected worker without combining conflicting assignments. The importer checks sequence, elapsed time, worker identities and legal cells and values. I defined the overlap model and concurrency and logging contracts and reviewed run evidence for the documented version of a joint course project. The 36 local acceptance tests covered malformed boards, unique, multiple and unsatisfiable inputs, termination, changed logs and replay; an independent oracle checked both modes. Captures on the public page show runs with a synthetic puzzle. Evidence does not establish general puzzle coverage or a speed advantage for ten workers. Source remains private.

[Published case study](https://yahyaalali.com/en/works/samurai-sudoku/) · [Back to index](../../README.md)
