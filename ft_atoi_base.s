global ft_atoi_base
section .text

extern ft_strlen

;int ft_atoi_base(char *str, char *base)
;  rdi -> str
;  rsi -> base
;
;   
;   rcx -> str
;   rdx -> base   
;   r8 -> incremento i
;   r9 -> incremento j
;   r12 -> signal (negative , positive)
;   r13 -> base_length
;   r14 -> value base

ft_atoi_base:

    push r12
    push r13
    push r14
    push rbx ; uso o bl
    sub rsp, 8 ; Alinha a stack (4 pushes + 8 bytes + 1 ret = 48 bytes)

    mov r8,-1 
    mov r12, 1
    mov rdx , rsi ; rdx = base
    mov rcx , rdi ; rcx = str

    ; Validate base
    ;❌ caracteres repetidos
    ;❌ + ou -
    ;❌ espaços (' ', \t, etc.)
    ;❌ menos de 2 caracteres

    mov rdi , rdx ; rdi = base
    call ft_strlen
    cmp rax, 2   ; se a base tiver menos que dois carateres 
    jl .error

    mov r13 , rax 

    .loop1:
        inc r8
        mov al , [rdx + r8] ; OR byte[rdx + r8]
        
        cmp al,0            ; while(base[i])
        je .base_OK

    .is_valid_base:

        cmp al , '+'    ; al == '+'
        je .error

        cmp al , '-'   ; al == '-'
        je .error

        cmp al, ' '    ; space
        je .error
        cmp al, 9      ; whitespace check (9-13)
        jl .ok
        cmp al, 13
        jbe .error

    .ok:
        mov r9 ,r8   ; j = i + 1
        inc r9

    .loop2:
        mov bl, [rdx + r9] ; while(base[j])
        cmp bl, 0
        je .loop1 
        
        cmp al, bl
        je .error


        inc r9
        jmp .loop2

    .base_OK:
        mov r8,-1

        .is_space:
            inc r8
            mov al , [rcx + r8] ; str[i]

            cmp al,' '
            je .is_space


        .is_signal:
            inc r8
            mov al , [rcx + r8]

            cmp al , '+'    ; al == '+'
            je .is_signal

            cmp al , '-'   ; al == '-'
            je .neg_signal

            jmp .after_signals
        
        .neg_signal:
            imul r12,r12,-1
            jmp .is_signal

        xor rax,rax ;-> valor do return a zero
        xor r14 ,r14 ;-> value base
        xor rax,rax ;-> valor do return a zero
        xor r14 ,r14 ; -> value base

        .after_signals:
            mov r8,0 ; incrmento i
            mov r9,-1 ; incrmento j

            .char_in_base:
            mov r9,-1 ; Reiniciar indice da base para cada char da string
            .search_base:
            inc r9
            mov al,  [rcx + r8] ; str[i]
            mov bl , [rdx + r9] ; base[j]

            cmp bl,0
            je .finish

            cmp al,bl
            jne .char_in_base
            jne .search_base

            mov r14, r9  ; determinate value of base

            imul rax,r13   ; rax = rax * r13  result = result * base_len + value_base
            add rax , r14      ; rax = rax + r14 


            
            cmp al , 0
            je .finish
            inc r8
            jmp .char_in_base

    .error:
        add rsp, 8
        pop rbx
        pop r14
        pop r13
        pop r12
        xor rax,rax
        ret

    .finish:
        imul rax, r12 ; Aplica o sinal (positivo ou negativo)
        add rsp, 8
        pop rbx
        pop r14
        pop r13
        pop r12
        ret
