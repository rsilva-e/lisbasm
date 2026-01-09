global ft_read
section .text

ft_read:


    ; rdi fd
    ; rsi *buf
    ; rdx count

    mov rax,0 ; 0 representa o write no syscall
    syscall
    ret