global _ft_tolower

section .text
_ft_tolower:
	push rbp
	mov rbp, rsp
	mov rax, rdi
	cmp rax, 65
	jl _ret
	cmp rax, 90
	jg _ret
	add rax, 32

_ret:
	leave
	ret
