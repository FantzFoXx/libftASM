# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalpha.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 14:08:14 by udelorme          #+#    #+#              #
#    Updated: 2018/10/06 14:08:15 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isalpha

section .text
_ft_isalpha:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cmp rdi, 65
	jl _no
	cmp rdi, 90
	jle _yes

	cmp rdi, 97
	jl _no
	cmp rdi, 122
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
