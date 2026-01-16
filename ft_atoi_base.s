global ft_atoi_base
section .text

extern ft_strlen
extern ft_write

;Validate base
;❌ caracteres repetidos
;❌ + ou -
;❌ espaços (' ', \t, etc.)
;❌ menos de 2 caracteres

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
;   r15 -> result


ft_atoi_base:

    push r12
    push r13
    push r14
    push r15
    push rbx ; uso o bl

    mov r8,-1 
    mov r12, 1
    mov rdx , rsi ; rdx = base
    mov rcx , rdi ; rcx = str
    xor r15, r15  ; Inicializar resultado a 0
 

    ; se a base tiver menos que dois carateres , da erro
    mov rdi , rdx ; rdi = base
    call ft_strlen
    cmp rax, 2   
    jl .error

    mov r8, -1
    mov r13 , rax 

    .loop1:
        inc r8
        mov al , [rdx + r8] ; 
        
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

            cmp al, ' '
            je .is_space
            cmp al, 9
            jb .is_signal  ; < (unsigned) ou seja nao existe espacos
            cmp al, 13
            jbe .is_space  ; <= (unsigned)



        .is_signal:

            cmp al , '+'    ; al == '+'
            je .is_space

            cmp al , '-'   ; al == '-'
            je .neg_signal

            jmp .after_signals
        
        .neg_signal:
            imul r12,r12,-1
            jmp .is_space

        .after_signals:
            mov r9,-1 ; incrmento j

            .char_in_base:
            inc r9
            mov al,  [rcx + r8] ; str[i] -> al
            mov bl, [rdx + r9] ; base[j] -> bl

            cmp bl,0
            je .finish

            cmp al,bl
            jne .char_in_base
 
            mov r14, r9  ; determinate value of base

            imul r15,r13   ; r15 = r15 * r13  result = result * base_len + value_base
            add r15 , r14  ; r15 = r15 + r14
            
            inc r8
            mov r9,-1 ; Reiniciar indice da base para cada char da base
            jmp .char_in_base

    .error:
        xor rax,rax
        jmp .restore

    .finish:
        mov rax,r15
        imul rax, r12 ; Aplica o sinal (positivo ou negativo)

    .restore:
        pop rbx
        pop r15
        pop r14
        pop r13
        pop r12
        ret

    .overflowpositive:
        mov rax, 2147483647      ; INT_MAX decimal
        jmp .restore

    .overflownegative:
        mov rax, -2147483648     ; INT_MIN decimal
        jmp .restore