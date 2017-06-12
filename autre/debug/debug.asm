section .data
	int_format: db "da int is %d", 0
	char_format: db "da char is %c", 0
	string_format: db "da string is %s", 0
	read_char_format: db "%s", 0
	my_char : db 0
	read_int_format : db "insert a int plz", 0
	nl: db 10, 0

section .text
	global _print_int
	global _print_string
	global _print_char
	global _read_char
	global _read_int
	extern _printf
	extern _scanf

_print_int:
	push rbp
	mov rbp, rsp
	mov rsi, rdi
	mov rdi, int_format
	call _printf
	leave
	ret

_print_string:
	push rbp
	mov rbp, rsp
	mov rsi, rdi
	mov rdi, string_format
	call _printf
	leave
	ret

_print_char:
	push rbp
	mov rbp, rsp
	mov rsi, [rdi]
	mov rdi, char_format
	call _printf
	leave
	ret

_print_nl:
	push rbp
	mov rbp, rsp
	mov rdi, nl
	call _printf
	leave
	ret

_read_char:
	push rbp
	mov rbp, rsp
	mov rdi, read_char_format
	mov rsi, my_char
	call _scanf
	mov rdi, my_char
	call _print_char
	leave
	ret

_read_int:
	push rbp
	mov rbp, rsp
	mov rdi, read_int_format
	call _scanf
	mov rdi, rsi
	call _print_int
	leave
	ret


