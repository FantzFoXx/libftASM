global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_memcpy
extern _ft_strnew

section .text
_ft_strdup:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cmp rdi, 0
	je _ret
	push rdi
	call _ft_strlen
	mov rdi, rax
	mov r8, rax
	push rdi
	call _ft_strnew
	;cmp rax, 0
	;je _ret

_cpy:
	pop rcx
	inc rcx
	mov rdi, rax
	pop rsi
	cld
	rep movsb
	
_ret:
	leave
	ret
