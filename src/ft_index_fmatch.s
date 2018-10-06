# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_index_fmatch.s                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 14:07:59 by udelorme          #+#    #+#              #
#    Updated: 2018/10/06 14:08:01 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_index_fmatch

section .text
_ft_index_fmatch:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cmp rdi, 0
	je _not_found
	mov rcx, 0

_find_char:
	cmp byte[rdi + rcx], 0
	je _not_found
	cmp byte[rdi + rcx], sil
	je _ret
	inc rcx
	jmp _find_char

_not_found:
	mov rcx, -1

_ret:
	mov rax, rcx
	leave
	ret
