.text
.global start

msg:
	.ascii "hello, world\n"

start:
	movl $1, %edi
	leaq msg(%rip), %rsi
	movl $13, %edx
	movl $0x02000004, %eax
	syscall
	xorl %edi, %edi
	movl $0x02000001, %eax
	syscall

