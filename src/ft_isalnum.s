global _ft_isalnum
extern _ft_isalpha
extern _ft_isdigit

section .text
_ft_isalnum:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	call _ft_isalpha
	cmp rax, 1
	je _yes
	call _ft_isdigit
	cmp rax, 1
	je _yes
	jmp _no

_yes:
	mov rax, 1
	jmp _ret

_no:
	mov rax, 0
	jmp _ret

_ret:
	leave
	ret
