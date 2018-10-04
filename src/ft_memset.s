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
	push rcx
	mov rcx, rdx
	mov rax, rsi
	rep stosb

_ret:
	pop rcx
	pop rdi
	mov rax, rdi
	leave
	ret
