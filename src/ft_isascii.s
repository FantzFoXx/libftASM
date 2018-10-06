# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isascii.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 14:08:18 by udelorme          #+#    #+#              #
#    Updated: 2018/10/06 14:08:19 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isascii

section .text
_ft_isascii:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cmp rdi, 0
	jl _no
	cmp rdi, 127
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
