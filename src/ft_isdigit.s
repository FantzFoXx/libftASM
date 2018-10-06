# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isdigit.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 14:08:22 by udelorme          #+#    #+#              #
#    Updated: 2018/10/06 14:08:23 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isdigit

section .text
_ft_isdigit:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cmp rdi, 48
	jl _no
	cmp rdi, 57
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
