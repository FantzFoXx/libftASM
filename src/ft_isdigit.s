global _ft_isdigit

section .text
_ft_isdigit:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cmp rdi, 48
	jl _no
	cmp rdi, 57
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
