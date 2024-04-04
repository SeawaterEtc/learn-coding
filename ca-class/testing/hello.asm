section .data
    message db "Hello, World!", 10  ; The string to print (with newline character)

section .text
    global _start

_start:
    mov rax, 1     ; Write the message to stdout (file descriptor 1)
    mov rdi, 1
    mov rsi, message
    mov rdx, 13  ; Length of the message
    syscall

    mov rax, 60     ; Exit the program
    xor rdi, rdi
    syscall
