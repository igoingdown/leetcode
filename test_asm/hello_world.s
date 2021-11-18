.text
.global start

db:
	.ascii "hello, world\n"

start:
	movl $1, %edi
	leaq db(%rip), %rsi
	movl $13, %edx
	movl $0x02000004, %eax
	syscall
	xorl %edi, %edi
	movl $0x02000001, %eax
	syscall

