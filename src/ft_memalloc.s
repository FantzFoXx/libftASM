global _ft_memalloc
extern _malloc
extern _ft_bzero

section .text
_ft_memalloc:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov r8, rdi
	call _malloc
	mov rdi, r8
	push rdi
	push rsi
	mov rsi, rdi
	mov rdi, rax
	call _ft_bzero
	pop rsi
	pop rdi

_ret:
	leave
	ret
