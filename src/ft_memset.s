global _ft_memset

section .text
_ft_memset:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	push rdi
	push rcx
	cmp rdi, 0
	je _ret
	cmp rdx, 0
	je _ret
	mov rcx, rdx
	mov rax, rsi
	rep stosb

_ret:
	pop rcx
	pop rdi
	mov rax, rdi
	leave
	ret
