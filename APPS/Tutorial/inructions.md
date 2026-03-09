| Instrukce | Co dělá                 |
| --------- | ----------------------- |
| ADD       | sčítá                   |
| SUB       | odčítá                  |
| CMP       | porovnává (bez uložení) |
| INC       | +1                      |
| DEC       | -1                      |
| NEG       | změní znaménko          |
| AND       | bitové AND              |
| TEST      | AND bez uložení         |
| OR        | bitové OR               |
| XOR       | bitové XOR              |
| NOT       | invertuje bity          |
| SHL       | posun doleva            |
| SHR       | posun doprava           |

# Flag

- they are automatically changed by instructions

| Flag   | Purpose              |
| ------ | -------------------- |
| **ZF** | equal / zero         |
| **CF** | unsigned comparisons |
| **SF** | negative result      |
| **OF** | signed overflow      |


# Podmíněné skoky

### Equality / Zero

These check the Zero Flag (ZF).

| Instruction   | Meaning              | Condition |
| ------------- | -------------------- | --------- |
| `JE` / `JZ`   | Jump if equal / zero | `ZF = 1` result = 0  |
| `JNE` / `JNZ` | Jump if not equal    | `ZF = 0`  |



### Nepodepsaná porovnání

Used when numbers are unsigned.

These use CF and ZF.

| Instruction | Meaning                | Condition         |
| ----------- | ---------------------- | ----------------- |
| `JA`        | Jump if above          | `CF=0` and `ZF=0` |
| `JAE`       | Jump if above or equal | `CF=0`            |
| `JB`        | Jump if below          | `CF=1`            |
| `JBE`       | Jump if below or equal | `CF=1` or `ZF=1`  |

>JE / JNE
>JG / JL / JGE / JLE
>JA / JB / JAE / JBE

