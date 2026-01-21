; -----------------------------------------------------------------------------
; Compare two strings, and return the difference between the first mismatched characters
;
; int	ft_strcmp(const char *str1, const char *str2);
; 
; Arguments / Registers used :
; rdi = *str1
; rsi = *str2
; rcx = counter (index i)
; rax = return value 
;
; -----------------------------------------------------------------------------

global ft_strcmp 
section .text

ft_strcmp:
    xor rcx,rcx

.loop:                          ; Load 1 byte from each strings
    mov al,byte[rdi+rcx]        ; str1[i]
    mov dl,byte[rsi+rcx]        ; str2[i]  
                                ; str1[i] == str2[i] 
    cmp al, dl                  
    jne .diff
                                ; str1[i] != str2[i] 
    cmp al, 0                   ; str1[1] == NULL
    je .equal                   

    inc rcx
    jmp .loop

    .diff:                      ; return str1[i] - str2[i] (32-bit)
        movzx eax, al
        movzx edx, dl
        sub eax,edx             
        ret

    .equal:
        xor eax,eax
        ret
