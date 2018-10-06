# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_tolower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 14:09:06 by udelorme          #+#    #+#              #
#    Updated: 2018/10/06 14:09:08 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_tolower

section .text
_ft_tolower:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rax, rdi
	cmp rax, 65
	jl _ret
	cmp rax, 90
	jg _ret
	add rax, 32

_ret:
	leave
	ret
