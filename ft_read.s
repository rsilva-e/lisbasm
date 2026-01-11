
;ssize_t ft_read(int fd, void *buf, size_t count);
; rdi fd
; rsi *buf
; rdx count

; Retorna um ponteiro para o errno da thread atual 
; int *__errno_location(void);


extern __errno_location

global ft_read
section .text

ft_read:


    mov rax,0 ; 0 representa o write no syscall
    syscall

    test rax,rax
    jl .error
    ret 


    .error:
        mov r12,rax    ; guardar o rax 
        neg r12
        call __errno_location wrt ..plt
        mov [rax],r12 ; coloca o conteudo no endereco do erro que apanhei na funcao erro
        mov rax , -1
        ret



