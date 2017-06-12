section .data
hello:
		.string db "String one %s and two %s", 10, 0
		.other db "Hello World" , 0
		.another db "Other", 0
	
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
		mov rdi, hello.string
		mov rsi, hello.other
		mov rdx, hello.another
		call _printf
		leave
		ret
