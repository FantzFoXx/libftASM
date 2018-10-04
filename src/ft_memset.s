global _ft_memset

section .text
_ft_memset:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cmp rdi, 0
	je _ret
	cmp rdx, 0
	je _ret
	push rdi
	mov rcx, rdx
	mov rax, rsi
	rep stosb

_ret:
	pop rax
	leave
	ret
