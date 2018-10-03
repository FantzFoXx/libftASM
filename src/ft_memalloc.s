global _ft_memalloc
extern _malloc
extern _ft_bzero

section .text
_ft_memalloc:
	push rbp
	mov rbp, rsp
	mov rax, rdi
	cmp rdi, 0
	je _ret
	mov r8, rdi
	call _malloc
	cmp rax, 0
	je _ret
	mov rdi, rax
	mov rsi, r8
	call _ft_bzero

_ret:
	leave
	ret
