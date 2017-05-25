section .data

section .text
	global start
	global _main
	global _loop_start
	extern _printf

start:
	call _main
	ret

_main:
	push rbp
	mov rbp, rsp
	mov rax, "hello"
	mov rdi, [rax]
	call _printf
	leave
	ret

_loop_start:
	add rax, rcx
	loop _loop_start	
		

