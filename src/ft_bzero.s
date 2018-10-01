global _ft_bzero
extern _ft_memset

section .text
_ft_bzero:
	push rbp
	mov rbp, rsp
	mov rdx, rsi
	push rsi
	mov rsi, 0
	call _ft_memset
	mov rax, rdi
	pop rsi

_ret:
	leave
	ret
