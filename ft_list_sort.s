
global ft_list_sort
section .text


; void    ft_list_sort(t_list **begin_list, int (*cmp)())
; rdi -> **begin_list
; rsi -> cmp
; rbx -> number of swaps
; r12 = current
; r13 = cmp function
; r14 = current->next
; 


ft_list_sort:

    push rbx
    push r12
    push r13
    push r14
    push r15

    ;mov rbx,rdi  ; rbx = **begin_List
    mov r12,[rdi] ; r12 = current
    mov r13, rsi  ; r13 = cmp function

    cmp r12,0
    je .done

    .loop1:
        mov r14,[r12+8]
        test r14,r14
        je .init

        .loop2:
            cmp r14,0
            je .init
            ;funcao compare
            mov rdi,[r12]
            mov rsi,[r14]
            call r13
            cmp eax,0
            jle .no_swap_data   ; cmp <= 0

            ;swap_data
            mov r15, [r12]
            mov rax,[r14]
            mov [r12],rax
            mov [r14],r15
            
            
    .no_swap_data:
        mov r14,[r14+8]
        jmp .loop2

    .init:
        mov r12,[r12+8] ; current = current->next
        test r12,r12
        je .done
        jmp .loop1

    .done:
        pop rbx
        pop r12
        pop r13
        pop r14
        pop r15
        ret

  
