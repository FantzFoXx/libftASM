global _ft_index_fmatch

section .text
_ft_index_fmatch:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je _not_found
	mov rcx, 0

_find_char:
	cmp byte[rdi + rcx], 0
	je _not_found
	cmp byte[rdi + rcx], sil
	je _ret
	inc rcx
	jmp _find_char

_not_found:
	mov rcx, -1

_ret:
	mov rax, rcx
	leave
	ret
