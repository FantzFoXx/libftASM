# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strnew.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 14:08:58 by udelorme          #+#    #+#              #
#    Updated: 2018/10/06 14:08:59 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_strnew
extern _ft_memalloc

section .text
_ft_strnew:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	inc rdi
	call _ft_memalloc
	;dec rdi

_ret:
	leave
	ret
