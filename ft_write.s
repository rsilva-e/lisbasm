global ft_write
section .text

ft_write:

    ; rdi - fd
    ; rsi - buf
    ; rdx - count

    mov rax, 1  ; 1 representa o write no syscall
    syscall


    ret

