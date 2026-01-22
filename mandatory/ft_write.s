; -----------------------------------------------------------------------------
; Writes a buffer to a file descriptor.
;
; ssize_t ft_write(int fd, const void *buf, size_t count);
;
; Arguments / Registers used:
; rdi = fd
; rsi = buf
; rdx = count
; rax = return value (number of bytes written, or -1 on error)
; r12 = store error
; -----------------------------------------------------------------------------

global ft_write
section .text
extern __errno_location


ft_write:
    
    mov rax,1                 ; syscall number for write
    syscall

    cmp rax ,0                ; if rax < 0 (error)
    jl .error

    ret

    .error:
        push r12
        neg rax
        mov r12, rax          ; save error number
        
        call __errno_location wrt ..plt

        mov [rax],r12         ; store error number at errno
        mov rax , -1
        
        pop r12
        ret
