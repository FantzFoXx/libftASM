# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_index_lmatch.s                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 14:08:04 by udelorme          #+#    #+#              #
#    Updated: 2018/10/06 14:08:05 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_index_lmatch
extern _ft_strlen

section .text
_ft_index_lmatch:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cmp rdi, 0
	je _not_found
	call _ft_strlen

_find_char:
	cmp rax, 0
	je _not_found
	dec rax
	cmp byte[rdi + rax], sil
	je _ret
	jmp _find_char

_not_found:
	mov rax, -1

_ret:
	leave
	ret
