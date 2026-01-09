
global ft_strcmp 
    section .text

ft_strcmp:

    xor rax,rax

    .loop:

        mov al,byte[rdi+rax]
        mov bl,byte[rsi+rax]

        cmp al,0
        je .done
        cmp bl,0
        je .done

        cmp al,bl
        mov rax,(al-bl)
        ret(al-bl)

    .done:
        xor rax,rax
        ret