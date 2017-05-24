%include	"asm_io.inc"

segment	.data

prompt1 db		"Enter a number: ", 0
prompt2 db		"Enter another number: ", 0
outmsg1 db		"You entered ", 0
outmsg2 db		" and ", 0
outmsg3 db		", the sum of these is ", 0

segment .bss

input resd 1
input resd 2

segment .text
	global 		_asm_main

_asm_main:
	enter		0, 0			; setup routine
	pusha

	mov			eax, prompt1 	; print out prompt
	call		print_string  

	call		read_int 		; read integer
	mov			[input1], eax	; store into input1

	mov			eax, prompt2	; print out prompt
	call		print_string

	call		read_int		; read integer
	mov			[input2], eax	; store into input2

	mov			eax, [input1]	; eax = dword at input1
	add			eax, [input2]	; eax += dword at input2
	mov			ebx, eax		; ebx = eax

	dump_regs	1				; print out register values
	dump_mem	2,  out_msg1, 1 ; print out memory

	mov			eax, outmsg1
	call		print_string	; print out firsrt message
	mov			eax, [input1]	
	call		print_int		; print out input1
	mov			eax, outmsg2
	call		print_string	; print out second message
	mov			eax, [input2]
	call		print_int		; print out input2
	mov			eax, outmsg3
	call		print_string	; print out third message
	mov			eax, ebx
	call		print_int		; print out sum (ebx)
	call		print_nl		; print new-line

	popa
	mov			eax, 0			; return back to C
	leave
	ret
