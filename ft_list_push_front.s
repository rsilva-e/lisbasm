extern malloc

global ft_list_push_front
section .text


ft_list_push_front:

    test rdi,rdi
    je .done


    mov r12,rdi  ; r12 = begin_list
    mov r13,rsi  ; r13 = data


    mov rdi,16
    call malloc wrt ..plt   ; malloc compatível com PIE - endereco relativo (PLT - Procedure Linkage Table)
    test rax,rax
    je .done

    mov [rax],r13
    mov r14,[r12] ; primeiro no do begin_list
    mov [rax + 8],r14 ; new->next = *begin_list
    mov [r12],rax  ; *begin_list = new node

    .done:
        ret 




