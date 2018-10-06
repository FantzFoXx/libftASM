/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:09:21 by udelorme          #+#    #+#             */
/*   Updated: 2018/10/06 14:11:01 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H

# include <unistd.h>

int		ft_isalpha(char s);
void	ft_bzero(void *s, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isalnum(int c);
int		ft_isapha(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
size_t	ft_strlen(char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strcat(char *s1, const char *s2);
int		ft_puts(const char *s);
void	ft_cat(int fd);
size_t	ft_index_fmatch(char *str, char match);
size_t	ft_index_lmatch(char *str, char match);
void	*ft_memalloc(size_t size);
char	*ft_strnew(size_t size);

#endif
