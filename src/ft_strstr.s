# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strstr.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 14:09:02 by udelorme          #+#    #+#              #
#    Updated: 2018/10/06 14:09:03 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_strstr
extern _ft_strlen

section .text
_ft_strstr:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	push rdi
	push rsi
	xor rax, rax
	cmp rdi, 0
	je _ret
	cmp rsi, 0
	je _ret
	cmp byte [rsi], 0
	je _ret
	call _ft_strlen
	cmp rax, 0
	je _ret
	mov r8, rax

_reset_rcx:
	xor rcx,rcx
	dec rax
	
_while_cmp:
	cmp rax, 0
	jl _ret_null
	mov r9, rax 
	add r9, rcx
	mov dl, [rdi + r9]
	mov dh, [rsi + rcx]
	cmp dh, 0
	je _ret
	inc rcx
	cmp dl, dh
	je _while_cmp
	jne _reset_rcx

_ret_null:
	mov rax, 0
	leave
	ret

;_ret_s1:
;	pop rsi
;	pop rdi
;	mov rax, rdi
;	leave
;	ret

_ret:
	add rdi, rax
	mov rax, rdi
	pop rsi
	pop rdi
	leave
	ret
