global _ft_strlen

section .text
_ft_strlen:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rax, 0
	cmp rdi, 0
	je _ret

_count:
	cmp byte[rdi+rax], 0x0
	je _ret
	inc rax
	jmp _count

_ret:
	leave
	ret
