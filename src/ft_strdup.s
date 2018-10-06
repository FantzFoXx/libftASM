# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 15:09:48 by udelorme          #+#    #+#              #
#    Updated: 2018/10/06 15:11:31 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_strdup
extern _ft_strlen
extern _ft_strnew

section .text
_ft_strdup:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	xor rax, rax
	cmp rdi, 0
	je _ret
	push rdi
	call _ft_strlen
	mov rdi, rax
	mov r8, rax
	push rdi
	call _ft_strnew
	cmp rax, 0
	je _ret_malloc_err

_cpy:
	pop rcx
	inc rcx
	mov rdi, rax
	pop rsi
	cld
	rep movsb
	jmp _ret

_ret_malloc_err:
	pop rcx
	pop rsi
	mov rax, 0
	
_ret:
	leave
	ret
