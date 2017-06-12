segment .data

	int_format	db "%i", 0
	
	global read_int
	global print_int
	global print_string
	global print_nl
	extern _printf

read_int:
	enter 4, 0
	pusha

print_int:
	enter 0, 0
	pusha
	pushf

	push eax
	push dword int_format
	call _printf
	pop ecx
	pop ecx

	popf
	popa
	leave
	ret
