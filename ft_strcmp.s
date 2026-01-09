
global ft_strcmp 
section .text

ft_strcmp:

    xor rcx,rcx

.loop:

    mov al,byte[rdi+rcx]
    mov bl,byte[rsi+rcx]
    
    cmp al,bl
    jne .diff

    test al,bl
    je .equal


    inc rcx
    jmp .loop


    .diff:
        movzx eax, al
        movzx ebx, bl
        sub eax,ebx
        ret

    .equal:
        xor eax,eax
        ret
