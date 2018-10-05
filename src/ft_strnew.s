global _ft_strnew
extern _ft_memalloc

section .text
_ft_strnew:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	inc rdi
	call _ft_memalloc
	;dec rdi

_ret:
	leave
	ret
