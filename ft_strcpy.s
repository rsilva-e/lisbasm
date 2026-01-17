

global ft_strcpy
    section .text


ft_strcpy:

    xor rcx,rcx  ; contador 
    xor rax,rax

    .loop:
        mov al,byte[rsi+rcx]
        cmp al,0
        je .done

        mov byte[rdi+rcx],al
        inc rcx
        jmp .loop
        
    .done:
        mov byte[rdi+rcx],0  
        mov rax,rdi
        ret  ;retorna o rax -> *dest
