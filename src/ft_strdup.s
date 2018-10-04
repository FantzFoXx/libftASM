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
	call _ft_strlen
	mov rdi, rax
	mov r8, rax
	call _ft_strnew
	
	mov rax, r8
	jmp _ret

	mov r9, rdi
	mov rdi, rax
	mov rsi, r9
	mov rdx, r8
	mov rax, r8
	;call _ft_memcpy

_ret:
	leave
	ret
