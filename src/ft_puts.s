%define syscall_base 0x02000000
%define write 0x4

global _ft_puts
extern _ft_strlen

section .data
strings:
	.eol db 10
	.len equ $ - strings.eol
	.null db "(null)", 10
	.null_len equ $ - strings.null

section .text
_ft_puts:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je _write_null
	call _ft_strlen
	cmp rax, 0
	je _write_eol
	mov rdx, rax
	mov rsi, rdi
	mov rdi, 1
	mov rax, syscall_base + write
	syscall
	cmp rax, 0
	je _fail
	jmp _write_eol

_write_null:
	lea rsi, [rel strings.null]
	mov rdx, strings.null_len
	mov rdi, 1
	mov rax, syscall_base + write
	syscall

_fail:
	mov rax, 10
	leave
	ret

_write_eol:
	mov rax, syscall_base + write
	mov rdi, 1
	mov rsi, strings.eol
	mov rdx, 1
	syscall

_ret:
	mov rax, 10
	leave
	ret
