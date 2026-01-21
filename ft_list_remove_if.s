; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
;
; Registos de entrada:
; rdi = **begin_list
; rsi = *data_ref
; rdx = cmp
; rcx = free_fct
;
; Registos temporários:
; --- Callee-saved (não-voláteis, sobrevivem a `call`) ---
; rbx = *data_ref (rsi)
; r12 = *current (ponteiro para o nó atual)
; r13 = *previous (ponteiro para o nó anterior)
; r14 = *tmp (ponteiro para o próximo nó, current->next)
; r15 = **begin_list (rdi)
;
; --- Caller-saved (voláteis, destruídos por `call`) ---
; rdx e rcx são guardados na stack porque as chamadas a `cmp` e `free` os destruiriam.
;----------------------------------------------


global ft_list_remove_if
section .text

extern free


ft_list_remove_if:
    
    push    rbx
    push    r12
    push    r13
    push    r14
    push    r15
    push    rdx         
    push    rcx

    test rdi,rdi
    je .done

    mov rbx, rsi   ; Salva data_ref (rsi) num registo callee-saved (rbx)
    mov r12,[rdi]  ; current=*begin_list
    xor r13 , r13    ; previous = NULL
    mov r15 , rdi ; guardar a lista

    test r12,r12
    je .done

    .loop:

        mov r14 ,[r12 + 8]  ; tmp = current->next

        mov rdi,[r12]
        mov rsi, rbx   ; Define o 2º argumento para cmp
        mov rdx, [rsp + 8] ; Recupera cmp da pilha (offset: rcx(0) + rdx(8) -> +8)
        call rdx

        test eax,eax  ; return value of function rdx, em 32 bits int eax
        je .equal
    
        ; ---------- not equal: nó não é removido ----------
        mov r13,r12 ; previous = current
        mov r12,r14 ; current = tmp proximo not
        test r12,r12 ; current != NULL
        je .done
        jmp .loop

    
    .equal:

        test r13,r13
        jne .previousexit ; if previous == NULL
        ; else
        ; previous == NULL
        mov [r15] , r14 ; somente para atualizar a cabeca da lista
        jmp .freenode

    .previousexit:
        mov [r13 + 8], r14 ; prev->next = tmp;
        
    .freenode:
        
        mov rdi, [r12]
        mov rcx, [rsp]     ; Recupera free_fct da pilha (está no topo, offset 0)
        call rcx       ; free data

        mov rdi,r12     ; endereço do nó
        call free wrt ..plt ; free(node)
        
        mov r12,r14 ; current = tmp
        test r12,r12 ; current != NULL
        je .done
        jmp .loop

    .done:
        pop     rcx
        pop     rdx
        pop     r15
        pop     r14
        pop     r13
        pop     r12
        pop     rbx
        ret