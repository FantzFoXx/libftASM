global _ft_strlen

section .text
_ft_strlen:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cmp rdi, 0
	je _ret
	push rdi
	xor al, al
	xor rcx, rcx
	not rcx
	cld
	repne scasb
	not rcx
	dec rcx
	mov rax, rcx
	pop rdi

_ret:
	leave
	ret
