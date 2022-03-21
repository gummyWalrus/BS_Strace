BITS 64

global main

section .text
    main:
        mov eax, 0x80
        syscall
        mov eax, 0
        ret