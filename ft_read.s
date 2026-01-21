; -----------------------------------------------------------------------------
; Reads a buffer to a file descriptor.
;
; ssize_t ft_read(int fd, void *buf, size_t count);
;
; Arguments / Registers used:
; rdi = fd
; rsi = buf
; rdx = count
; rax = return value (number of bytes read, or -1 on error)
; -----------------------------------------------------------------------------

global ft_read
section .text

extern __errno_location

ft_read:

    mov rax,0               ; syscall number for read
    syscall

    test rax,rax            ; if rax < 0 (error)
    jl .error

    ret 

    .error:
        push r12            ; Perseve r12
        mov r12,rax         
        neg r12
        
        call __errno_location wrt ..plt
        mov [rax],r12d      ; store error number at errno
        mov rax , -1
        
        pop r12             ; Restore r12
        ret
