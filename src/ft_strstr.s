section .text
	global _ft_strstr
	extern _ft_strlen

_ft_strstr:
	push rbp
	mov rbp, rsp
	sub rsp, 32
	cmp rdi, 0
	je _null
	cmp rsi, 0
	je _null
	cmp byte [rsi], 0
	je _back_hay
	cmp byte [rdi], 0
	je _null
	mov qword [rbp - 8], rdi
	mov qword [rbp - 16], rsi
	mov qword [rbp - 32], rdi
	mov rdi, qword [rbp - 16]
	call _ft_strlen
	mov qword [rbp - 24], rax
	mov rdi, qword [rbp - 8]
_top_loop:
	mov rdi, qword [rbp - 32]
_main_loop:
	mov rsi, qword [rbp - 16]
	mov al, byte [rsi]
	cmp byte [rdi], 0
	je _null
	cmp byte [rdi], al
	je _cmp
	inc rdi
	jmp _main_loop
_cmp:
	mov qword [rbp - 32], rdi
	mov rcx, qword [rbp - 24]
	cld
	repe cmpsb
	dec rdi,
	dec rsi
	mov al, byte [rsi]  ; cmp rdi-sring ref vs rsi-substring
	cmp byte [rdi], al
	je _back_nee
	mov rdi, qword [rbp - 32]
	inc rdi
	mov qword [rbp - 32], rdi
	jmp _top_loop
_null:
	xor rax, rax
	jmp _end
_back_hay:
	mov rax, rdi
	jmp _end
_back_nee:
	mov rax, qword [rbp - 32]
_end:
	leave
	ret
