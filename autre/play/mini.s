section .data	
hello:
	.string db "Hello"

section .text
	global _main
	extern _printf

_main:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	lea rdi, [rel data.string]
	call _printf
	leave
	ret	
