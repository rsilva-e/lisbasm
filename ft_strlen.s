


global ft_strlen
    section .text

ft_strlen:

    xor rax,rax

    .loop:
        cmp byte[rdi],0
        je .done
        inc rax
        inc rdi
        jmp .loop  ;retorna para o inicio do loop sem verificação

    .done:
        ret  ;retorna o rax

