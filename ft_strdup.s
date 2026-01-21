; -----------------------------------------------------------------------------
; Duplicates a string.
;
; char	*ft_strdup(const char *str);
; 
; Arguments / Registers used:
; rdi = *str
; r12 = rdi
; rax = return pointer of string
; 
; -----------------------------------------------------------------------------

global ft_strdup
extern ft_strcpy
extern ft_strlen
extern malloc

section .text
ft_strdup:

    push r12                        ; perseve r12
    mov r12,rdi                     ; r12 = rdi

    call ft_strlen                  ; get lenght of string
    add rax,1                       ; add 1 for null terminator
 
    mov rdi,rax                     ; rdi = rax argument for malloc
    call malloc wrt ..plt           

    test rax,rax                    ; if malloc fail (rax == 0)
    je .done
   

    mov rdi, rax                    ; first argument of ft_strcpy (destination)
    mov rsi, r12                    ; second argument of ft_strcpy (source)
    call ft_strcpy

    pop r12                         
    ret

.done:                              ; return 0 
    xor rax,rax                     
    pop r12
    ret
