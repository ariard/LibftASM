%define SIZE	128
%define RD		0x2000000 | 3
%define WR		0x2000000 | 4


section .bss
	buffer resd 100	

section .text
	global _ft_cat
	extern _ft_bzero	
	extern _printf

_ft_cat:
	push rbp
	mov rbp, rsp
	cmp edi, 0
	jl _end
	sub rsp, 16
	mov dword [rbp - 4], edi
_read:
	lea rdi, [rel buffer]
	mov rsi, SIZE
	call _ft_bzero
	lea rsi, [rel buffer]
	mov edi, dword [rbp - 4]
	mov rdx, SIZE
	mov rax, RD
	syscall	
	cmp eax, -1
	je _end
	mov dword [rbp - 8], eax
	mov edi, 1
	mov edx, eax
	mov rax, WR
	syscall
	mov eax, dword [rbp - 8]
	cmp eax, 0
	jg _read
_end:
	leave
	ret
