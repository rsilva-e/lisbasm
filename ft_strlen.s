; -----------------------------------------------------------------------------
; Counts the number of characters in a string.
;
; size_t	ft_strlen(const char *s);
; 
; Arguments / Registers used:
; rdi = *s
; rax = return value (lenght)
;
; -----------------------------------------------------------------------------

global ft_strlen
    section .text

ft_strlen:

    xor rax,rax             ; rax = 0 (lenght)

    .loop:
        cmp byte[rdi],0     ; Compare current byte with null terminator
        je .done
        inc rax             ; rax++ 
        inc rdi             ; rdi++
        jmp .loop  

    .done:
        ret                 ; return rax (string length)
