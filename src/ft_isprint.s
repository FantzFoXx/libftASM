# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isprint.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 14:08:26 by udelorme          #+#    #+#              #
#    Updated: 2018/10/06 14:08:27 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isprint

section .text
_ft_isprint:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cmp rdi, 32
	jl _no
	cmp rdi, 126
	jg _no
	jmp _yes

_yes:
	mov rax, 1
	jmp _ret

_no:
	mov rax, 0
	jmp _ret

_ret:
	leave
	ret
