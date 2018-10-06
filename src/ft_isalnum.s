# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalnum.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 14:08:08 by udelorme          #+#    #+#              #
#    Updated: 2018/10/06 14:08:10 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isalnum
extern _ft_isalpha
extern _ft_isdigit

section .text
_ft_isalnum:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	call _ft_isalpha
	cmp rax, 1
	je _yes
	call _ft_isdigit
	cmp rax, 1
	je _yes
	jmp _no

_yes:
	mov rax, 1
	jmp _ret

_no:
	mov rax, 0
	jmp _ret

_ret:
	leave
	ret
