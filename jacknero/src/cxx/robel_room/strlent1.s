	.file	"strlent1.cpp"
	.text
	.align 2
.globl _Z6strlenPc
	.type	_Z6strlenPc, @function
_Z6strlenPc:
.LFB2:
	pushl	%ebp
.LCFI0:
	movl	%esp, %ebp
.LCFI1:
	subl	$16, %esp
.LCFI2:
	movl	$0, -4(%ebp)
	jmp	.L2
.L3:
	addl	$1, -4(%ebp)
.L2:
	movl	-4(%ebp), %eax
	addl	8(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L3
	movl	-4(%ebp), %eax
	leave
	ret
.LFE2:
	.size	_Z6strlenPc, .-_Z6strlenPc
.globl __gxx_personality_v0
	.section	.rodata
	.align 4
.LC0:
	.string	"\346\226\207\345\255\227\345\210\227[%s]\343\201\256\351\225\267\343\201\225\343\201\257%d\343\203\220\343\202\244\343\203\210\343\201\247\343\201\231\343\200\202\n"
	.text
	.align 2
.globl _Z10DispLengthPc
	.type	_Z10DispLengthPc, @function
_Z10DispLengthPc:
.LFB3:
	pushl	%ebp
.LCFI3:
	movl	%esp, %ebp
.LCFI4:
	subl	$24, %esp
.LCFI5:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_Z6strlenPc
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	leave
	ret
.LFE3:
	.size	_Z10DispLengthPc, .-_Z10DispLengthPc
	.section	.rodata
.LC1:
	.string	"\350\244\222\343\202\201\346\255\251\343\203\241\343\203\274\343\203\253"
	.align 4
.LC2:
	.string	"\345\230\230\343\201\244\343\201\215\343\202\203\345\274\265\343\202\214\343\202\213\343\201\234\343\203\211\343\203\253\343\203\220\343\203\203\343\202\255\343\203\274"
.LC3:
	.string	""
	.text
	.align 2
.globl main
	.type	main, @function
main:
.LFB4:
	leal	4(%esp), %ecx
.LCFI6:
	andl	$-16, %esp
	pushl	-4(%ecx)
.LCFI7:
	pushl	%ebp
.LCFI8:
	movl	%esp, %ebp
.LCFI9:
	pushl	%ecx
.LCFI10:
	subl	$4, %esp
.LCFI11:
	movl	$.LC1, (%esp)
	call	_Z10DispLengthPc
	movl	$.LC2, (%esp)
	call	_Z10DispLengthPc
	movl	$.LC3, (%esp)
	call	_Z10DispLengthPc
	movl	$0, %eax
	addl	$4, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
.LFE4:
	.size	main, .-main
	.section	.eh_frame,"a",@progbits
.Lframe1:
	.long	.LECIE1-.LSCIE1
.LSCIE1:
	.long	0x0
	.byte	0x1
	.string	"zP"
	.uleb128 0x1
	.sleb128 -4
	.byte	0x8
	.uleb128 0x5
	.byte	0x0
	.long	__gxx_personality_v0
	.byte	0xc
	.uleb128 0x4
	.uleb128 0x4
	.byte	0x88
	.uleb128 0x1
	.align 4
.LECIE1:
.LSFDE3:
	.long	.LEFDE3-.LASFDE3
.LASFDE3:
	.long	.LASFDE3-.Lframe1
	.long	.LFB3
	.long	.LFE3-.LFB3
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI3-.LFB3
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI4-.LCFI3
	.byte	0xd
	.uleb128 0x5
	.align 4
.LEFDE3:
.LSFDE5:
	.long	.LEFDE5-.LASFDE5
.LASFDE5:
	.long	.LASFDE5-.Lframe1
	.long	.LFB4
	.long	.LFE4-.LFB4
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI6-.LFB4
	.byte	0xc
	.uleb128 0x1
	.uleb128 0x0
	.byte	0x9
	.uleb128 0x4
	.uleb128 0x1
	.byte	0x4
	.long	.LCFI7-.LCFI6
	.byte	0xc
	.uleb128 0x4
	.uleb128 0x4
	.byte	0x4
	.long	.LCFI8-.LCFI7
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI9-.LCFI8
	.byte	0xd
	.uleb128 0x5
	.byte	0x4
	.long	.LCFI10-.LCFI9
	.byte	0x84
	.uleb128 0x3
	.align 4
.LEFDE5:
	.ident	"GCC: (GNU) 4.2.3 (Ubuntu 4.2.3-2ubuntu7)"
	.section	.note.GNU-stack,"",@progbits
