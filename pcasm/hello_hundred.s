section .data
hello:
	.string db "Hello World", 10, 0
	.len equ $ - hello.string

section .text
	global _main
	global _start

start:
	call _main
	ret

_main:
	push rbp
	mov rbp, rsp
	sub rsp, 0x10
	mov DWORD [rbp-0x4], 0x0
	mov DWORD [rbp-0x8], 0x186A0
_write_hello:
	add DWORD [rbp-0x4], 0x1
	mov rdi, 1
	lea rsi, [rel hello.string]
	mov rdx, hello.len
	mov rax, 0x2000000 | 4
	syscall
	mov esi, DWORD [rbp-0x4]
	cmp esi, DWORD [rbp-0x8]
	jl _write_hello
	leave
	ret	
