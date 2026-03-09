
global negate
global g_int_output

section .data
    ; dd allocates storage for 32 bit ints
    g_int_array dd -3, -8, 80, 2710, 32, 439, 9099, 10, 77, -273, 2, 22222, 0, -23, 23
    g_int_output dd 0


section .text

        negate:
            xor rbx, rbx ;mov rbx, 0 (ZF = 1)

            lea rsi, [rel g_int_array] ;  rsi point to the arr start. lea loads only address
            ; mov rsi, g_int_array - it loads actual data

            mov rcx, 15 ;pocet prvku pole

        count_smycka:
            mov eax, [rsi] ;[rsi] dereferences the pointer. it retrieves the val stored at MA rsi points to.

            ;LSB = 0 -> even AND 1 = 0 → ZF = 1 (Zero Flag set)
            test eax,1 ; provede: eax AND 1 → result (effects FLAGs), 

            jnz preskocit ;skoci pokud neni nula (if liche cislo)

            inc rbx ;Pokud je číslo sudé -> zvýšíme čítač. 1 byt

        preskocit:
            add rsi, 4 ; presune 4 bajty, protoze kazde cislo ma 32 bitu. int = 4 bajty

            loop count_smycka ;implicitne DEC rcx - 1. snizi hodnotu rcx a skoci zpet.

            ;priklad:
            ;mov rcx, 10
            ;count:
            ; body
            ;loop count ;implicite snizit

            ;priklad2:
            ;move rbx, 10
            ;count:
            ; body
            ;dec rbx ;explicitne snizit

            mov eax, ebx
            xor edx, edx
            mov ecx, 4
            div ecx
            mov eax, edx
            neg eax
            mov [rel g_int_output], eax
            ret





            











    
