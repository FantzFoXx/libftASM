global _ft_strcat

section .text
_ft_strcat:
	push rbp
	mov rbp, rsp
	cmp rax, 0
	je _no
	cmp rax, 0
	je _no
	je _yes

_yes:
	mov rax, 1
	jmp _ret

_no:
	mov rax, 0
	jmp _ret

_ret:
	leave
	ret
