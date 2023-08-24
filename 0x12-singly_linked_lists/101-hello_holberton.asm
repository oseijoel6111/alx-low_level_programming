section .data
    hello db "Hello, Holberton", 10, 0

section .text
    global main

    extern printf

main:
    push rbp            ; Align stack
    mov rdi, hello      ; Load the address of the hello string into rdi
    call printf         ; Call printf with the address of the hello string
    add rsp, 8          ; Clean up the stack
    xor rax, rax        ; Return 0 from the main function
    ret

