global ft_list_remove_if
section .text

; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
; rdi begin_list
; rsi data_ref
; rdx cmp
; rcx free_fct


ft_list_remove_if:


    test[rdi],[rdi]
    je .done

    test rdi,rdi
    je .done

    mov r12,[rdi]  ; current=*begin_list
    mov r13 , 0    ; previous = NULL



    .loop:


        cmp [r12],rsi
        je .equal



        jmp .loop


    .equal
        








    .done 
        ret