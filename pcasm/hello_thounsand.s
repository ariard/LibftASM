section .data
hello:
	.string db "Hello World", 10, 0
	.len equ $ - hello.string
	.test db "TEST", 10, 0
int_format: db "%i", 0

section .bss
	ONE resd 1
	TWO	resd 2	

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
	mov dword [rcx], 0
	call _write_hello
	leave
	ret

_write_hello:
	mov rdi, 1
	lea rsi, [rel hello.string]
	mov rdx, hello.len
	mov rax, 0x2000000 | 4
	syscall
	mov dword [ONE], 50
	mov dword [TWO], 100
	inc rcx
	jmp _write_hello
_end:
	leave
	ret


_my_print:
	push rbp
	mov rbp, rsp
	mov rdi, int_format
	mov rsi, rbx
	call _printf
	leave
	ret
