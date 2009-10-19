	.file	"meta.cpp"
	.text
	.p2align 4,,15
	.type	_GLOBAL__I_main, @function
_GLOBAL__I_main:
.LFB1172:
	pushl	%ebp
.LCFI0:
	movl	%esp, %ebp
.LCFI1:
	subl	$24, %esp
.LCFI2:
	movl	$_ZStL8__ioinit, (%esp)
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, 8(%esp)
	movl	$_ZStL8__ioinit, 4(%esp)
	movl	$_ZNSt8ios_base4InitD1Ev, (%esp)
	call	__cxa_atexit
	leave
	ret
.LFE1172:
	.size	_GLOBAL__I_main, .-_GLOBAL__I_main
	.section	.ctors,"aw",@progbits
	.align 4
	.long	_GLOBAL__I_main
	.text
	.p2align 4,,15
.globl main
	.type	main, @function
main:
.LFB1023:
	leal	4(%esp), %ecx
.LCFI3:
	andl	$-16, %esp
	pushl	-4(%ecx)
.LCFI4:
	pushl	%ebp
.LCFI5:
	movl	%esp, %ebp
.LCFI6:
	pushl	%edi
.LCFI7:
	pushl	%esi
.LCFI8:
	pushl	%ebx
.LCFI9:
	pushl	%ecx
.LCFI10:
	subl	$296, %esp
.LCFI11:
	movl	%gs:20, %eax
	movl	%eax, -20(%ebp)
	xorl	%eax, %eax
	movl	$6, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	call	_ZNSolsEi
	movl	%eax, %edx
	movl	%eax, -292(%ebp)
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%edx,%eax), %ebx
	testl	%ebx, %ebx
	je	.L14
	xorl	%eax, %eax
	cmpb	$0, 28(%ebx)
	leal	-276(%ebp), %esi
	jne	.L15
	.p2align 4,,7
	.p2align 3
.L11:
	movb	%al, (%esi,%eax)
	addl	$1, %eax
	cmpl	$256, %eax
	jne	.L11
	movl	(%ebx), %edx
	leal	29(%ebx), %edi
	leal	-20(%ebp), %eax
	movl	%edi, 12(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	movl	%ebx, (%esp)
	call	*28(%edx)
	movl	$256, %ecx
	movb	$1, 28(%ebx)
	repz cmpsb
	jne	.L16
.L8:
	movl	(%ebx), %eax
	movl	$10, 4(%esp)
	movl	%ebx, (%esp)
	call	*24(%eax)
.L6:
	movsbl	%al,%eax
	movl	%eax, 4(%esp)
	movl	-292(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZNSo3putEc
	movl	%eax, (%esp)
	call	_ZNSo5flushEv
	xorl	%eax, %eax
	movl	-20(%ebp), %edx
	xorl	%gs:20, %edx
	jne	.L17
	addl	$296, %esp
	popl	%ecx
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
.L16:
	movb	$2, 28(%ebx)
	jmp	.L8
.L15:
	movzbl	39(%ebx), %eax
	jmp	.L6
.L17:
	.p2align 4,,7
	.p2align 3
	call	__stack_chk_fail
.L14:
	.p2align 4,,6
	.p2align 3
	call	_ZSt16__throw_bad_castv
.LFE1023:
	.size	main, .-main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.weakref	_ZL20__gthrw_pthread_oncePiPFvvE,pthread_once
	.weakref	_ZL27__gthrw_pthread_getspecificj,pthread_getspecific
	.weakref	_ZL27__gthrw_pthread_setspecificjPKv,pthread_setspecific
	.weakref	_ZL22__gthrw_pthread_createPmPK14pthread_attr_tPFPvS3_ES3_,pthread_create
	.weakref	_ZL22__gthrw_pthread_cancelm,pthread_cancel
	.weakref	_ZL26__gthrw_pthread_mutex_lockP15pthread_mutex_t,pthread_mutex_lock
	.weakref	_ZL29__gthrw_pthread_mutex_trylockP15pthread_mutex_t,pthread_mutex_trylock
	.weakref	_ZL28__gthrw_pthread_mutex_unlockP15pthread_mutex_t,pthread_mutex_unlock
	.weakref	_ZL26__gthrw_pthread_mutex_initP15pthread_mutex_tPK19pthread_mutexattr_t,pthread_mutex_init
	.weakref	_ZL30__gthrw_pthread_cond_broadcastP14pthread_cond_t,pthread_cond_broadcast
	.weakref	_ZL25__gthrw_pthread_cond_waitP14pthread_cond_tP15pthread_mutex_t,pthread_cond_wait
	.weakref	_ZL26__gthrw_pthread_key_createPjPFvPvE,pthread_key_create
	.weakref	_ZL26__gthrw_pthread_key_deletej,pthread_key_delete
	.weakref	_ZL30__gthrw_pthread_mutexattr_initP19pthread_mutexattr_t,pthread_mutexattr_init
	.weakref	_ZL33__gthrw_pthread_mutexattr_settypeP19pthread_mutexattr_ti,pthread_mutexattr_settype
	.weakref	_ZL33__gthrw_pthread_mutexattr_destroyP19pthread_mutexattr_t,pthread_mutexattr_destroy
	.section	.eh_frame,"a",@progbits
.Lframe1:
	.long	.LECIE1-.LSCIE1
.LSCIE1:
	.long	0x0
	.byte	0x1
.globl __gxx_personality_v0
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
.LSFDE1:
	.long	.LEFDE1-.LASFDE1
.LASFDE1:
	.long	.LASFDE1-.Lframe1
	.long	.LFB1172
	.long	.LFE1172-.LFB1172
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI0-.LFB1172
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI1-.LCFI0
	.byte	0xd
	.uleb128 0x5
	.align 4
.LEFDE1:
.LSFDE3:
	.long	.LEFDE3-.LASFDE3
.LASFDE3:
	.long	.LASFDE3-.Lframe1
	.long	.LFB1023
	.long	.LFE1023-.LFB1023
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI3-.LFB1023
	.byte	0xc
	.uleb128 0x1
	.uleb128 0x0
	.byte	0x9
	.uleb128 0x4
	.uleb128 0x1
	.byte	0x4
	.long	.LCFI4-.LCFI3
	.byte	0xc
	.uleb128 0x4
	.uleb128 0x4
	.byte	0x4
	.long	.LCFI5-.LCFI4
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI6-.LCFI5
	.byte	0xd
	.uleb128 0x5
	.byte	0x4
	.long	.LCFI10-.LCFI6
	.byte	0x84
	.uleb128 0x6
	.byte	0x83
	.uleb128 0x5
	.byte	0x86
	.uleb128 0x4
	.byte	0x87
	.uleb128 0x3
	.align 4
.LEFDE3:
	.ident	"GCC: (Ubuntu 4.3.3-5ubuntu4) 4.3.3"
	.section	.note.GNU-stack,"",@progbits
