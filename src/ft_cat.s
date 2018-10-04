%define syscall_base 0x02000000
%define read  0x3
%define write 0x4
%define size_read 4096

global _ft_cat

section .data
    buf: times size_read db 0

section .text
_ft_cat:
	push rbp
	mov rbp, rsp
	sub rsp, 16

_setup:
	lea r8, [rel buf]
	cmp rdi, 0
	jl _ret
	mov r10, rdi

_read:
	mov rsi, r8
	mov rax, syscall_base + read
	mov rdi, r10
	mov rdx, size_read
	syscall
	jc _ret
	mov r9, rax
	mov byte[r8 + rax], 0
	cmp rax, 0
	je _ret

_print:
	mov rsi, r8
	mov rdx, r9
	mov rdi, 1
	mov rax, syscall_base + write
	syscall
	jmp _read

_ret:
	leave
	ret
