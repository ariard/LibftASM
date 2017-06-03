section .data
	my_format: db "da test", 0
	int_format: db "da int is %x", 0	

section .text
	global start
	global _main
	extern _printf

start:
	call _main
	ret

_main:
	push rbp
	mov rbp, rsp
	mov rsi, my_format
	mov rdi, [rsi]
	call _printf
	leave
	ret 
