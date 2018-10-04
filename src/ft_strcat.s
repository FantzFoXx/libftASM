global _ft_strcat
extern _ft_strlen
extern _ft_memcpy

section .text
_ft_strcat:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cmp rdi, 0
	je _ret
	cmp rsi, 0
	je _ret
	push rdi
	call _ft_strlen
	mov rcx, rax
	add rdi, rax ; s1 + taille
	push rdi ; push s1 + taille
	mov rdi, rsi ; s2
	call _ft_strlen
	mov rdx, rax ; s2 len
	pop rdi ; get s1 + taille
	mov byte[rdi + rax], 0
	call _ft_memcpy
	pop rax

_ret:
	leave
	ret
