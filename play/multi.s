section .text
	global _start
	global _main
	extern _printf

section .data
	A db 5

_start:
	call _main
	ret
_main:
	push rbp
	mov rbp, rsp
	mov A, 10
	mov rdi, A
	call _printf
	leave
	ret
