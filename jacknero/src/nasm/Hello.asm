section .text
global _start

_start:
        mov  eax, 4 ;write
        mov  ebx, 1 ;stdout
        mov  ecx, msg
        mov  edx, msglen
        int  0x80
        ;
        mov  eax,1
        int 0x80

msg    db          'hello!', 0x0A
msglen  equ        $  - msg
