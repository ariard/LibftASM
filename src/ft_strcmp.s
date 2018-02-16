%define MAX 	0x7FFFFFFFFFFFFFFF 

section	.data
	int_format: db "int is ", 0

section .text
	global _ft_strcmp
	extern _ft_strlen
	extern _printf

_ft_strcmp:
	push rbp
	mov rbp, rsp
	sub	rsp, 20
	xor rax, rax
	cmp rdi, 0
	je _end
	cmp rsi, 0
	je _end
	mov qword [rbp - 8], rdi
	mov qword [rbp - 16], rsi
	call _ft_strlen
	mov dword [rbp - 20], eax
	mov rdi, qword [rbp - 16]
	call _ft_strlen
	xor rcx, rcx
	cmp eax, dword [rbp - 20]
	jg _less
	mov ecx, eax
	jmp _cmp
_less:
	mov ecx, dword [rbp - 20]
_cmp:	
	mov rdi, qword [rbp - 8]
	mov rsi, qword [rbp - 16]
	cld
	repe cmpsb
	dec rdi
	dec rsi
	xor rax, rax
	mov al, byte [rdi]
	sub al, byte [rsi]
	movsx eax, al
_end:
	leave
	ret
