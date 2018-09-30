global _ft_isascii

section .text
_ft_isascii:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	jl _no
	cmp rdi, 127
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
