global _ft_toupper

section .text
_ft_toupper:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rax, rdi
	cmp rax, 97
	jl _ret
	cmp rax, 122
	jg _ret
	sub rax, 32

_ret:
	leave
	ret
