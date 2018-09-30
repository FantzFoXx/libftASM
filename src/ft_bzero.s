global _ft_bzero

section .text
_ft_bzero:
	push rbp
	mov rbp, rsp
	mov rcx, rdi
	mov rdx, rsi
	cmp rcx, 0
	je _ret

_loop:
	cmp rcx, 0
	je _ret
	mov byte[rcx], 0
	dec rdx
	inc rcx
	jl _loop
	jmp _ret

_ret:
	leave
	ret
