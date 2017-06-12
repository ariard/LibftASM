section .data
hello:
		.string db "Hello World", 10, 0
		.len equ $ - hello.string
	
section	.text	
		global _main
		global _start
		extern _printf

start:
		call _main
		ret
_main:
		push rbp
		mov rbp, rsp
		call _loop_hello
_loop_hello:
		mov rdi, 1
		lea rsi, [rel hello.string] 
		mov rdx, hello.len
		mov rax, 0x2000000 | 4
		syscall
		jmp _loop_hello

		leave
		ret

