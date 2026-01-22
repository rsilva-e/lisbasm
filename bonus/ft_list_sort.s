; -----------------------------------------------------------------------------
; Sort list using a comparison function
;
; void    ft_list_sort(t_list **begin_list, int (*cmp)());
; 
; Arguments / Registers used :
; rdi = **begin_list
; rsi = cmp fucntion
; r12 = current
; r13 = cmp fucntion
; r14 = current->next
; r15 = tmp (temporary swap)
; -----------------------------------------------------------------------------


global ft_list_sort
section .text

ft_list_sort:

    push r12
    push r13
    push r14
    push r15

    test rdi, rdi                   ; if begin_list == NULL
    je .done

    mov r12,[rdi]                   ; r12 = *begin_list
    mov r13, rsi                    ; r13 = cmp function

    cmp r12,0                       ; if current == NULL
    je .done

    .loop1:
        mov r14,[r12 + 8]           ; next = current->next
        test r14,r14                ; if next == NULL
        je .init

        .loop2:
            cmp r14,0
            je .init

            mov rdi,[r12]          
            mov rsi,[r14]
            sub rsp, 8              ; align stack to 16 + 8 bytes
            call r13                ; call cmp
            add rsp, 8                     

            cmp eax,0               ; cmp <= 0
            jle .no_swap_data       

                                    ; swap data
            mov r15,[r12]           
            mov rax,[r14]
            mov [r12],rax           ; current->data = next->data
            mov [r14],r15           ; next->data = tmp
            
            
    .no_swap_data:
        mov r14,[r14 + 8]           
        jmp .loop2

    .init:
        mov r12,[r12 + 8]           ; current = current->next
        test r12,r12                ; if current->next == NULL
        je .done
        jmp .loop1

    .done:
        pop r12
        pop r13
        pop r14
        pop r15
        ret

  
