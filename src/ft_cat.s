%define syscall_base 0x02000000
%define read  0x3
%define write 0x4
%define size_read 128*1024

global _ft_cat
extern _malloc

section .text
_ft_cat:
	push rbp
	mov rbp, rsp

_setup:
	sub rsp, size_read
	lea r8, [rsp - size_read]
	cmp rdi, 0
	ja _ret
	mov r10, rdi

_read:
	mov rsi, r8
	mov rax, syscall_base + read
	mov rdi, r10
	mov rdx, size_read
	syscall
	mov r9, rax
	cmp rax, 0
	je _ret
	mov byte[r8 + size_read], 0

_print:
	mov rsi, r8
	mov rdx, r9
	mov rdi, 1
	mov rax, syscall_base + write
	syscall
	xor rcx, rcx
	jmp _read

_find_eof:
	cmp rcx, size_read
	je _read
	cmp byte[rsi + rcx], -1
	je _ret
	inc rcx
	jmp _find_eof

_ret:
	add rsp, size_read
	leave
	ret
