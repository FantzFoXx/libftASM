# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 14:08:54 by udelorme          #+#    #+#              #
#    Updated: 2018/10/06 14:08:55 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_strlen

section .text
_ft_strlen:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cmp rdi, 0
	je _ret
	push rdi
	xor al, al
	xor rcx, rcx
	not rcx
	cld
	repne scasb
	not rcx
	dec rcx
	mov rax, rcx
	pop rdi

_ret:
	leave
	ret
