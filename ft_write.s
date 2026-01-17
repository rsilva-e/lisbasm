global ft_write
section .text
extern __errno_location


;ssize_t ft_write(int fd, const void *buf, size_t count);
    ; rdi - fd
    ; rsi - buf
    ; rdx - count


ft_write:

    mov rax,1    ; represent write in syscall
    syscall

    cmp rax ,0  ; if rax < 0 
    jl .error

    ret

    .error:
        neg rax
        mov rdx, rax ; save error of write

        sub rsp,8
        call __errno_location wrt ..plt
        add rsp,8

        mov [rax],rdx
        mov rax , -1
        ret
