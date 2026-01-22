; -----------------------------------------------------------------------------
; Counts the number of nodes in the list.
;
; int ft_list_size(t_list *begin_list);
; 
; Arguments / Registers used :
; rdi = *begin_list
; rax = return value (size)
;
; -----------------------------------------------------------------------------


global ft_list_size
section .text

ft_list_size:
    xor rax,rax         ; rax = 0

.loop:
    test rdi,rdi        ; if rdi == NULL
    je .done

    inc rax             ; increment rax
    mov rdi,[rdi + 8]   ; rdi = current->next
    jmp .loop

.done:
    ret                 ; return size in rax
