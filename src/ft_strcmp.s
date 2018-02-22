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
	sub rsp, 24
	xor rax, rax
	cmp rdi, 0
	je _null
	cmp rsi, 0
	je _null
	mov qword [rbp - 8], rdi
	mov qword [rbp - 16], rsi
	call _ft_strlen
	mov qword [rbp - 24], rax
	mov rdi, qword [rbp - 16]
	call _ft_strlen
	xor rcx, rcx
	cmp rax, qword [rbp - 24]
	jg _less
	mov rcx, rax
	jmp _cmp
_less:
	mov rcx, qword [rbp - 24]
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
	jmp _end
_null:
	xor eax, eax
_end:
	leave
	ret
