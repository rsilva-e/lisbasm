
global ft_list_size
section .text

ft_list_size:
    xor rax,rax
    mov r12,rdi

.loop:
    test r12,r12
    je .done

    inc rax 
    mov r12,[r12+8]
    
    jmp .loop

.done:
    ret
