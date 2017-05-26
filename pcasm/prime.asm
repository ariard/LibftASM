segment .data
Message		db		"Find primes up to: ", 0

segment .bss
Limit		resd	1
Guess		resd	1

segment .text
	global _asm_main

_asm_main:
	mov eax, Message

