global _ft_memcpy

section .text
_ft_memcpy:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	push rdi
	cmp rdi, 0
	je _ret
	cmp rsi, 0
	je _ret
	cmp rdx, 0
	je _ret
	mov rcx, rdx
	;cld
	rep movsb

_ret:
	pop rax
	leave
	ret
