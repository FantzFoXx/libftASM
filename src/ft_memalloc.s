# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memalloc.s                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 14:08:31 by udelorme          #+#    #+#              #
#    Updated: 2018/10/06 14:23:30 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_memalloc
extern _malloc
extern _ft_bzero

section .text
_ft_memalloc:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov r8, rdi
	call _malloc
	cmp rax, 0
	je _ret
	mov rdi, r8
	push rdi
	push rsi
	mov rsi, rdi
	mov rdi, rax
	call _ft_bzero
	pop rsi
	pop rdi

_ret:
	leave
	ret
