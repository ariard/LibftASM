section .data
result:
		.gagne db "Gagne", 10, 0
		.len equ $ - result.gagne
		.perdu db "Perdu", 10, 0

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
	mov rax, _second_part
	call _first_part
	mov rdi, result.perdu
	call _printf
	leave
	ret
_first_part:
	push rax
	ret	
_second_part:
	mov rdi, 1
	lea rsi, [rel result.gagne]
	mov rdx, result.len
	mov rax, 0x2000000 | 4
	syscall
	leave
	ret
