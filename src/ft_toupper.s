# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_toupper.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 14:09:10 by udelorme          #+#    #+#              #
#    Updated: 2018/10/06 14:09:11 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_toupper

section .text
_ft_toupper:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rax, rdi
	cmp rax, 97
	jl _ret
	cmp rax, 122
	jg _ret
	sub rax, 32

_ret:
	leave
	ret
