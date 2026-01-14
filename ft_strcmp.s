
global ft_strcmp 
section .text

ft_strcmp:
    xor rcx,rcx

.loop:
    mov al,byte[rdi+rcx]
    mov dl,byte[rsi+rcx]    ; Usamos dl (parte do rdx) que é volátil/rascunho
    
    cmp al, dl
    jne .diff

    cmp al, 0       ; A forma correta de verificar o fim da string.
    je .equal       ; Se al é 0, e sabemos que al==bl, então ambas as strings terminaram.

    inc rcx
    jmp .loop


    .diff:
        movzx eax, al
        movzx edx, dl
        sub eax,edx
        ret

    .equal:
        xor eax,eax
        ret
