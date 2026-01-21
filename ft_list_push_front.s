; -----------------------------------------------------------------------------
; Inserts a new node at the beginning of the list.
; Allocates memory via malloc (PLT) and updates *begin_list.
;
; void ft_list_push_front(t_list **begin_list, void *data);
; 
; Arguments / Registers used :
; rdi = **begin_list
; rsi = *data
; r12 = **begin_list
; r13 = *data
; r14 = *begin_list
; -----------------------------------------------------------------------------


extern malloc

global ft_list_push_front
section .text


ft_list_push_front:

    test rdi,rdi
    je .done                        ; if **begin_list == NULL

    push r12                        ; perserve caller-saved
    push r13
    push r14

    mov r12,rdi         
    mov r13,rsi  

    mov rdi,16                      ; size of t_list (2 pointers: data + next)
    call malloc wrt ..plt           ; malloc compatível com PIE - endereco relativo (PLT - Procedure Linkage Table)
    test rax,rax
    je .done

    mov [rax], r13                  ; new->data = data
    mov r14, [r12]                  ; r14 = old first node
    mov [rax + 8], r14              ; new->next = old first node
    mov [r12], rax                  ; *begin_list = new node


    .done:
        pop r14                     ; restore registers 
        pop r13
        pop r12
        ret 
