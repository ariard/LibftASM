section .data

hello:
	.string db "hello", 10

section .text
	global start
	global _main
	extern _printf
start:
	call _main
	ret

_foo:	
	push rbp
	mov rsp, rbp
	sub 0x10, rsp
	lea 0x67(rip), rax
	mov rdi, -0x8(rbp)
	mov -0x8(rbp), rsi
	mov rax, rdi
	call 0x1000000f84
	mov eax, -0xc(rbp)
	add 0x10, rsp
	pop rbp
	ret
	nop (rax, rax)

_main:
	push rbp
	mov rsp, rsp
	sub rsp, 16
	sub 0x10, rsp
	lea 0x3a(rip), rdi
	mov 0x0, -0x4(rbp)
	call _foo
	xor eax, eax
	add 0x10, rsp
	pop rbp
	ret
