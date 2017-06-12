section .text
	global start
	global _main
	global _debut
	global _suite

start:
	call _main
	ret

_main:
	push rbp
	mov rbp, rsp
	call _debut

_debut:
	mov eax, 2
	jmp _suite

_suite:
	mov ebx, eax
