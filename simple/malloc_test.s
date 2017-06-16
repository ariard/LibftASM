section .text
	global _malloc_test
	extern _malloc

_malloc_test:
	push rbp
	mov rbp, rsp
	call _malloc
	leave
	ret
