; stores variables. Defines initialized data (stored in memory).
section .data


; actual text/code that is being run
section .text

global _start ; export


;it is called a LABEL
_start:
    MOV eax, 1 ;eax tells what we wanna do, 1 means we means exit the program
    MOV ebx, 1 ;whatever we put into ebx is status code
    INT 80h    ;it calls to operating system and says i need to do something

