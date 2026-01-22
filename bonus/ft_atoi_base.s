; -----------------------------------------------------------------------------
; Convert a string in a given base to an integer.
;
; int ft_atoi_base(char *str, char *base)
; 
; Arguments / Registers used::
; rdi = str
; rsi = base 
; rax = return value 
; rcx = str
; rdx = base 
; r8 = incremento i
; r9 = incremento j
; r12 = signal (negative , positive)
; r13 = base_length
; r14 = value base
; r15 = result
; -----------------------------------------------------------------------------

; Validate base:
; ❌ No duplicate characters
; ❌ '+' or '-' not allowed
; ❌ Spaces or tabs not allowed
; ❌ Base must have at least 2 characters



global ft_atoi_base
section .text

extern ft_strlen
extern ft_write

ft_atoi_base:

    push rbx 
    push r12
    push r13
    push r14
    push r15
    push rcx
    push rdx
    
    mov r8,-1                   ; r8 = -1
    mov r12, 1                  ; r12 = 1 (signal)
    mov rdx , rsi               ; rdx = *base
    mov rcx , rdi               ; rcx = *str
    xor r15, r15                ; r15 = 0 (initialize result)
 
                                ;Check base length (must be >= 2)
    mov rdi , rdx               
    call ft_strlen
    cmp rax, 2   
    jl .error

    ;mov r8, -1
    mov r13 , rax 

    .loop1:
        inc r8
        mov al , [rdx + r8]     ; al = base[i]
        
        cmp al,0                ; while(base[i])
        je .base_OK
                                
                                ; Check invalid characters in base
    .is_valid_base:

        cmp al , '+'            
        je .error

        cmp al , '-'            
        je .error

        cmp al, ' '             
        je .error
        cmp al, 9               
        jl .ok
        cmp al, 13
        jbe .error

    .ok:                        ; j = i + 1
        mov r9 ,r8              
        inc r9

    .loop2:
        mov bl, [rdx + r9]      ; bl = base[j]
        cmp bl, 0               ; while(base[j])
        je .loop1 
        
        cmp al, bl
        je .error


        inc r9
        jmp .loop2

    .base_OK:
        mov r8,-1
                                ; check if space exists
        .is_space:
            inc r8
            mov al , [rcx + r8] ; str[i] 

            cmp al, ' '
            je .is_space
            cmp al, 9
            jb .is_signal       ; < (unsigned) 
            cmp al, 13
            jbe .is_space       ; <= (unsigned)



        .is_signal:

            cmp al , '+'        
            je .is_space

            cmp al , '-'        
            je .neg_signal

            jmp .after_signals
        
        .neg_signal:
            imul r12,r12,-1
            jmp .is_space

        .after_signals:
            mov r9,-1           ; index j

        .char_in_base:
            inc r9
            mov al,  [rcx + r8] ; al = str[i] 
            mov bl, [rdx + r9]  ; bl = base[j] 

            cmp bl,0
            je .finish

            cmp al,bl
            jne .char_in_base
 
            mov r14, r9         ; determinate value of base
                                ; result = result * base_len + value_base
            imul r15,r13        
            add r15 , r14       
            
            inc r8
            mov r9,-1           
            jmp .char_in_base

    .error:
        xor rax,rax
        jmp .restore

    .finish:
        mov rax,r15
        imul rax, r12           ; apply sign

    .restore:
        pop rcx
        pop rdx
        pop rbx
        pop r12
        pop r13
        pop r14
        pop r15
        ret

    .overflowpositive:
        mov rax, 2147483647     ; INT_MAX
        jmp .restore

    .overflownegative:
        mov rax, -2147483648    ; INT_MIN
        jmp .restore