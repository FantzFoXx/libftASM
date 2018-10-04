global _ft_bzero
extern _ft_memset

section .text
_ft_bzero:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	push rdx
	mov rdx, rsi
	push rsi
	mov rsi, 0
	call _ft_memset
	pop rsi
	pop rdx

_ret:
	leave
	ret
