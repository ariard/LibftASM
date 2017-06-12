section .data
hello:
	.string db "Hello World", 0
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
	mov edi, 0x0
	mov esi, 0x64
	mov DWORD [rbp-0x4], 0x0
	call _foo
	xor esi, esi
	mov DWORD [rbp-0x8], eax
	mov eax, esi
	add rsp, 0x10
	pop rbp
	ret

_foo:
	push rbp
	mov rbp, rsp
	sub rsp, 0x10
	mov DWORD [rbp-0x4], edi
	mov DWORD [rbp-0x8], esi
	mov esi, DWORD [rbp-0x4]
	cmp esi, DWORD [rbp-0x8]
	jge _end
	mov edi, 0x1
	lea rsi, [rel hello.string]
	mov rdx, hello.len
	mov rax, 0x2000000 | 4
	syscall
	mov edi, DWORD [rbp-0x4]
	add edi, 0x1
	mov esi, DWORD [rbp-0x8]
	mov QWORD [rbp-0x10], rax
	call _foo
_end:
	add rsp, 0x10
	pop rbp
	ret
