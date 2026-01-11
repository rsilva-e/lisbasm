global ft_strdup
extern ft_strcpy
extern ft_strlen
extern malloc


section .text
ft_strdup:

    mov r12,rdi ; usar um registor que nao e destruido por chamda de funcoes

    call ft_strlen
    add rax,1
 
    mov rdi,rax ; argumento malloc
    call malloc wrt ..plt   ; ✅ compatível com PIE

    test rax,rax  ; return do malloc
    je .done
   
    mov rdi,rax ; 1 argumento ft_strcpy
    mov rsi,r12 ; 2 argumento ft_strcpy
    call ft_strcpy

    ret

.done:
    xor rax,rax
    ret
