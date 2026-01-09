

global ft_strcpy
    section .text


ft_strcpy:

    xor rax,rax

    .loop:
        mov bl,byte[rsi+rax]
        cmp bl,0
        je .done

        mov byte[rdi+rax],bl
        inc rax
        jmp .loop
        
    .done:
        mov byte[rdi+rax],0  
        mov rax,rdi
        ret  ;retorna o rax