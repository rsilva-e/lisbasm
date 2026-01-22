; -----------------------------------------------------------------------------
; Copy a string from src to dest
;
; char *ft_strcpy(char *dest, const char *src);
; 
; Arguments / Registers used :
; rdi = *dest
; rsi = *src
; rax = return *dest
;
; -----------------------------------------------------------------------------

global ft_strcpy
    section .text

ft_strcpy:

    xor rcx,rcx                   ; size_t i = 0
    xor rax,rax                   ; put all the bit zero (clear rax)

    .loop:
        mov al,byte[rsi+rcx]      ; load 1 byte from src 
        cmp al,0                  ; if src[i] == '\0'
        je .done

        mov byte[rdi+rcx],al      ; dest[i] = src[i]
        inc rcx
        jmp .loop
        
    .done:                       
        mov byte[rdi+rcx],0       ; dest[i] = '\0'
        mov rax,rdi               ; return *dest
        ret                      
