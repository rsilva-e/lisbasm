; -----------------------------------------------------------------------------
; Remove nodes from a list if cmp(node->data, data_ref) == 0.
; Frees the node data using free_fct and frees the node itself.
; Updates *begin_list when the head node is removed.
;
; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
; 
; Arguments:
; rdi = **begin_list
; rsi = *data_ref
; rcx = cmp
; rdx = free_fct
; 
; Registers used:
; rbx = *data_ref
; r12 = *begin_list
; r13 = *previous
; r14 = tmp 
; r15 = **begin_list
; -----------------------------------------------------------------------------


global ft_list_remove_if
section .text

extern free

ft_list_remove_if:
    
    ;Build stack frame
    push    rcx
    push    rdx         
    push    rbx
    push    r12
    push    r13
    push    r14
    push    r15


    test rdi,rdi
    je .done

    mov rbx, rsi                    ; Save data_ref
    mov r12,[rdi]                   ; r12 = *begin_list
    xor r13 , r13                   ; previous = NULL
    mov r15 , rdi                   ; r15 = **begin_list

    test r12,r12
    je .done

    .loop:

        mov r14 ,[r12 + 8]          ; tmp = current->next

        mov rdi,[r12]               ; current->data
        mov rsi, rbx                ; data_ref
        mov rdx, [rsp + 40]         ; load cmp function
        call rdx

        test eax,eax                ;  check value cmp (32 bits)
        je .equal
    
                                    ; node is not remove
        mov r13,r12                 ; previous = current
        mov r12,r14                 ; current = tmp next node
        test r12,r12                ; current != NULL
        je .done
        jmp .loop

    
    .equal:                         ; node must be removed
        test r13,r13                ; if previous != NULL
        jne .previousexits   
        mov [r15] , r14             ; update head node
        jmp .freenode

    .previousexits:
        mov [r13 + 8], r14          ; previous->next = tmp;
        
    .freenode:
        mov rdi, [r12]
        mov rcx, [rsp + 48]         ; load free_fct function 
        call rcx                    

        mov rdi,r12                 
        call free wrt ..plt         ; free(node)
        
        mov r12,r14                 ; current = tmp
        test r12,r12                ; current != NULL
        je .done
        jmp .loop

    .done:
        pop     rcx
        pop     rdx
        pop     rbx
        pop     r12
        pop     r13
        pop     r14
        pop     r15
        ret
