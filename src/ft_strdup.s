global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_memcpy

section .text
_ft_strdup:
	push rbp
	mov rbp, rsp
	mov rax, rdi
	cmp rdi, 0
	je _ret
	call _ft_strlen
	push rdi ; -> push src
	mov rdi, rax ; len
	push rdi ; push len
	call _malloc
	cmp rax, 0
	je _ret
	pop rdx ; -> pop len
	;dec rdx
	mov byte[rax + rdx], 0
	pop rsi ; -> pop src
	mov rdi, rax ; src
	call _ft_memcpy

_ret:
	leave
	ret
