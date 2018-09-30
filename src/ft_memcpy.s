global _ft_memcpy

section .text
_ft_memcpy:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je _ret
	cmp rsi, 0
	je _ret
	cmp rdx, 0
	je _ret
	push rdi
	mov rcx, rdx
	rep movsb

_ret:
	pop rax
	leave
	ret
