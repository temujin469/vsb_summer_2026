global combineColors
global decodeThermo

section .text

; int combineColors(char *rgba)
; rdi = pointer to rgba[4]
; returns eax = combined 32bit value

combineColors:

    ; zero alpha channel
    mov byte [rdi+3], 0

    ; load bytes
    movzx eax, byte [rdi]      ; r
    movzx ebx, byte [rdi+1]    ; g
    movzx ecx, byte [rdi+2]    ; b
    movzx edx, byte [rdi+3]    ; alpha 0

    ; combine
    shl ebx, 8
    shl ecx, 16
    shl edx, 24

    or eax, ebx
    or eax, ecx
    or eax, edx

    ret
;    0x00FF0F78
;= 00000000 11111111 00001111 01111000
;  └─────────┬────────┘ └──┬──┘ └──┬──┘
;    Alpha (0)         Blue(255) R(120)
;                      Green(15)


; void decodeThermo(
;       uint64_t data,
;       int *isValid,
;       int *wholePart,
;       unsigned int *decimalPart)
;
; rdi = data
; rsi = pointer to isValid
; rdx = pointer to wholePart
; rcx = pointer to decimalPart

decodeThermo:

    mov rax, rdi          ; copy data

    ; extract flags, upper 32 bits
    mov r8, rax
    shr r8, 32
    and r8, 1
    mov [rsi], r8d        ; store isValid

    ; extract whole part 16–31bits
    mov r9, rax
    shr r9, 16
    and r9, 0xFFFF
    movsx r9d, r9w        ; signed 16bit
    mov [rdx], r9d

    ; extract decimal part 0–15bits
    mov r10, rax
    and r10, 0xFFFF
    mov [rcx], r10d

    ret