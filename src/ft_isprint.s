global _ft_isprint

section .text
_ft_isprint:
	push rbp
	mov rbp, rsp
	cmp rdi, 32
	jl _no
	cmp rdi, 126
	jg _no
	jmp _yes

_yes:
	mov rax, 1
	jmp _ret

_no:
	mov rax, 0
	jmp _ret

_ret:
	leave
	ret
