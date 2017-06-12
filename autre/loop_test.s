section .data
hello : 
			.string db "hello world", 0

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
	mov rax, 0 
	mov rcx, 10
	call _loop_start
	leave
	ret

_loop_start:
	push rbp
	mov rbp, rsp
	mov rdi, hello.string
	call _printf
	add eax, ecx
	loop _loop_start
	leave
	ret

