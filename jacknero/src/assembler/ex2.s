.data
hello:  .string "Hello World!\n"

.text
.globl main
main:
  pushl %ebp
  movl %esp, %ebp
  pushl $hello
  call printf
  leave
  ret

