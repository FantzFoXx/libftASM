# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 14:08:34 by udelorme          #+#    #+#              #
#    Updated: 2018/10/06 14:08:35 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_memcpy

section .text
_ft_memcpy:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	push rdi
	cmp rdi, 0
	je _ret
	cmp rsi, 0
	je _ret
	cmp rdx, 0
	je _ret
	mov rcx, rdx
	;cld
	rep movsb

_ret:
	pop rax
	leave
	ret
