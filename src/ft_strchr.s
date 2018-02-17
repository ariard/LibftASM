%define MAX 	0x7FFFFFFFFFFFFFFF 

section .text
	global _ft_strchr
	extern _ft_strlen

_ft_strchr:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je _null
	sub rsp, 8
	mov qword [rbp - 8], rdi
	call _ft_strlen
	cmp rax, 0
	je _null
	mov rdi, qword [rbp - 8]
	add rax, 1
	mov rcx, rax
	mov al, sil		; set al as char to search
	cld
	repne scasb 	
	dec rdi
	cmp byte [rdi], sil ; cmp if match happen
	jne _null 
	mov rax, rdi
	jmp _end
_null:
	xor rax, rax
_end:
	leave
	ret
