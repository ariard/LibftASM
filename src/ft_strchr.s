%define MAX 	0x7FFFFFFFFFFFFFFF 

section .text
	global _ft_strchr

_ft_strchr:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je _end
	mov rcx, MAX
	mov ax, si
	cld
	repne scasb 	; dec rdi ?
	dec rdi
	mov rax, rdi
_end:
	leave
	ret
