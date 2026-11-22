# Residue Number System and CRT

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

**Locally tested educational implementation**

## Design and implementation

The application encodes a non-negative integer as its remainders over a non-empty list of distinct, pairwise-coprime moduli greater than one. Addition, subtraction and multiplication work componentwise. CRT combines the channel residues with modular inverses to obtain the unique canonical value from zero to the product of the moduli, excluding that product. For moduli 3, 5 and 7, the range has 105 values. Modular division requires a positive divisor invertible in every channel. Invalid residue vectors and unsupported moduli are rejected.

## Verification, limits and availability

I defined the input domain, separated the arithmetic core from the interface and built the reference application and correctness checks. The original coursework was shared; the page does not assign undocumented individual roles. Local tests covered encoding and reconstruction for all 105 representatives and all 11,025 ordered pairs for each of addition, subtraction and multiplication, plus invalid inputs. A separate unsigned binary divider was compared with divmod in 86,870 cases at widths of one to eight bits. These checks establish neither general performance nor hardware results. The public case study is available; the source remains private.

[Published case study](https://yahyaalali.com/en/works/residue-number-system-crt/) · [Back to index](../../README.md)
