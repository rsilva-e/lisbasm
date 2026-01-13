global ft_list_remove_if
section .text

extern free

;typedef struct s_list
;{
;    void *data;    [rdi]
;    struct s_list *next; [rdi + 8]
;} t_list;


;| Tipo de retorno em C | Registo correto |
;| -------------------- | --------------- |
;| `int` / `int32_t`    | `eax`           |
;| `long` / ponteiro    | `rax`           |
;| `char` / `short`     | `al` / `ax`     |




; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
;
; Registos de entrada:
; rdi = begin_list
; rsi = data_ref
; rdx = cmp
; rcx = free_fct
;
; Registos temporários:
; 
;
; r12 = current list
; rbx = data_ref

; r13 = previous
; r14 = tmp



; 
;----------------------------------------------




ft_list_remove_if:

    ;push    rbp         ; Alinhamento e frame pointer (opcional, mas ajuda no debug)
    push    rbx
    ;push   
    push    r12
    push    r13
    push    r14
    push    r15

    ; mas estes argumentos podem ser destruidos em call function , nao pode ser rdx nem rcx called -saved
    push    rdx         ; cmp function
    push    rcx         ; free_fct function
    
 
    ; A pilha já está alinhada aqui (7 pushes + 1 ret = 64 bytes, multiplo de 16). Não precisamos de sub rsp, 8.

    test rdi,rdi
    je .done_restore

    mov rbx, rsi   ; Salva data_ref (rsi) num registo callee-saved (rbx)
    mov r12,[rdi]  ; current=*begin_list
    xor r13 , r13    ; previous = NULL
    mov r15 , rdi ; guardar a lista


    test r12,r12
    je .done_restore


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
        je .done_restore
        jmp .loop


    
    .equal:
        
        test r13,r13
        jne .previousexit ; previous = NULL
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
        je .done_restore
        jmp .loop




    .done_restore:
        pop     rcx
        pop     rdx
        pop     r15
        pop     r14
        pop     r13
        pop     r12
        pop     rbx
        ;pop     rbp
        ret