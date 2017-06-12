section .data
	int_format: db "Ret : %d", 10, 0

section .text
	global _main
	global _start
	extern _printf

start:
	call _main
	ret

_main:
	push rbp
	mov rbp, rsp	
	mov bl, 0
	mov rcx, 64
	mov rax, 15
count_loop:
	shl rax, 1
	jnc skip_inc
	inc bl
skip_inc:
	loop count_loop
	mov rdi, int_format
	mov rsi, rbx
	call _printf
	leave
	ret
