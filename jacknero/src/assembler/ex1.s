.text
.globl main


main:
  movl $1, %eax
  movw $0xFFFF, %ax
  movb $0b01010101, %ah
  ret
