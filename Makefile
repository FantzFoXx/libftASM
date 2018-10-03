# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/28 05:27:21 by udelorme          #+#    #+#              #
#    Updated: 2018/10/03 19:25:42 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a
CC = ~/.brew/bin/nasm
#CC = ~/Downloads/nasm-2.13.03/nasm
FLAGS = -f macho64
SRC_PATH = src/
OBJ_PATH = obj/

SRC = ft_bzero.s ft_isalpha.s ft_isdigit.s ft_memcpy.s ft_puts.s ft_strdup.s  ft_tolower.s ft_isalnum.s ft_isascii.s ft_isprint.s ft_memset.s  ft_strcat.s  ft_strlen.s  ft_toupper.s ft_cat.s ft_index_fmatch.s ft_index_lmatch.s ft_memalloc.s

OBJ = $(addprefix $(OBJ_PATH), $(SRC:.s=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

$(OBJ): $(OBJ_PATH)%.o: $(SRC_PATH)%.s
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -rf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
