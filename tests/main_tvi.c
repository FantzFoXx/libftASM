/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:32:19 by tvisenti          #+#    #+#             */
/*   Updated: 2018/10/06 15:08:01 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libfts.h"

char *ft_display_bzero(int i)
{
	char s[101] = "salut toi !";
	char *s2;

	ft_bzero(s, i);
	s2 = strdup(s);
	return (s2);
}

int			main(void)
{
	printf("\n---------------------\n");
	printf("ft_isalpha:\n");
	printf("'\\n' => %d\n", ft_isalpha(10));
	printf("'@' => %d\n", ft_isalpha(64));
	printf("'A' => %d\n", ft_isalpha(65));
	printf("']' => %d\n", ft_isalpha(93));
	printf("'s' => %d\n", ft_isalpha(115));
	printf("130 => %d\n", ft_isalpha(130));

	printf("\n---------------------\n");
	printf("ft_isdigit:\n");
	printf("'\\n' => %d\n", ft_isdigit(10));
	printf("'/' => %d\n", ft_isdigit(47));
	printf("'0' => %d\n", ft_isdigit(48));
	printf("'9' => %d\n", ft_isdigit(57));
	printf("':' => %d\n", ft_isdigit(58));
	printf("'A' => %d\n", ft_isdigit('A'));

	printf("\n---------------------\n");
	printf("ft_isalnum:\n");
	printf("'1' => %d\n", ft_isalnum(49));
	printf("'@' => %d\n", ft_isalnum(64));
	printf("'A' => %d\n", ft_isalnum(65));
	printf("']' => %d\n", ft_isalnum(93));
	printf("'s' => %d\n", ft_isalnum(115));
	printf("10 => %d\n", ft_isalnum(10));

	printf("\n---------------------\n");
	printf("ft_isascii:\n");
	printf("'1' => %d\n", ft_isascii(49));
	printf("'@' => %d\n", ft_isascii(64));
	printf("'A' => %d\n", ft_isascii(65));
	printf("']' => %d\n", ft_isascii(93));
	printf("'s' => %d\n", ft_isascii(115));
	printf("10 => %d\n", ft_isascii(10));

	printf("\n---------------------\n");
	printf("ft_isprint:\n");
	printf("1 => %d\n", ft_isprint(1));
	printf("'@' => %d\n", ft_isprint(64));
	printf("'A' => %d\n", ft_isprint(65));
	printf("']' => %d\n", ft_isprint(93));
	printf("127 => %d\n", ft_isprint(127));
	printf("10 => %d\n", ft_isprint(10));

	printf("\n---------------------\n");
	printf("ft_tolower:\n");
	printf("'a' => %c\n", ft_tolower('a'));
	printf("'A' => %c\n", ft_tolower('A'));
	printf("'Z' => %c\n", ft_tolower('Z'));
	printf("'z' => %c\n", ft_tolower('z'));
	printf("'1' => %c\n", ft_tolower('1'));
	printf("'$' => %c\n", ft_tolower('$'));

	printf("\n---------------------\n");
	printf("ft_toupper:\n");
	printf("'a' => %c\n", ft_toupper('a'));
	printf("'A' => %c\n", ft_toupper('A'));
	printf("'Z' => %c\n", ft_toupper('Z'));
	printf("'z' => %c\n", ft_toupper('z'));
	printf("'1' => %c\n", ft_toupper('1'));
	printf("'$' => %c\n", ft_toupper('$'));

	/*
	printf("\n---------------------\n");
	printf("ft_bzero:\n");
	printf("'2' => %s\n", ft_display_bzero(2));
	printf("'11' => %s\n", ft_display_bzero(11));
	printf("'100' => %s\n", ft_display_bzero(100));
	printf("'12' => %s\n", ft_display_bzero(12));
	printf("'10' => %s\n", ft_display_bzero(10));
	*/


	printf("\n---------------------\n");
	printf("ft_strcat:\n");
	char str[50];
	str[0] = '\0';
	printf("'je ' => %s\n", ft_strcat(str, "je "));
	printf("'suis ' => %s\n", ft_strcat(str, "suis "));
	printf("'' => %s\n", ft_strcat(str, ""));
	printf("'un ' => %s\n", ft_strcat(str, "un "));
	printf("'TEST!' => %s\n", ft_strcat(str, "TEST!"));

	printf("\n---------------------\n");
	printf("ft_puts:\n");
	ft_puts("je");
	ft_puts("suis");
	ft_puts("");
	ft_puts("un");
	ft_puts("TEST!");
	ft_puts(NULL);

	printf("\n---------------------\n");
	printf("ft_strlen:\n");
	printf("True: [%zu] = Mine: [%zu]\n", strlen("Test 1"), ft_strlen("Test 1"));
	printf("True: [%zu] = Mine: [%zu]\n", strlen("a"), ft_strlen("a"));
	printf("True: [%zu] = Mine: [%zu]\n", strlen(""), ft_strlen(""));
	printf("True: [%zu] = Mine: [%zu]\n", strlen("Test 123456789"), ft_strlen("Test 123456789"));
	printf("True: [%zu] = Mine: [%zu]\n", strlen("\0Test 123456"), ft_strlen("\0Test 123456"));
	printf("True: [%zu] = Mine: [%zu]\n", strlen("Test 123456\0789"), ft_strlen("Test 123456\0789"));

	printf("\n---------------------\n");
	printf("ft_memset:\n");
	char tab[3][3];
	tab[0][0] = 15;
	printf("%c\n\n", tab[0][0]);
	ft_memset(tab[0], 48, 3);
	ft_memset(tab[1], 72, 3);
	ft_memset(tab[2], 90, 3);
	printf("[%c] = [%c]\n", tab[0][0], tab[0][2]);
	printf("[%c] = [%c]\n", tab[1][0], tab[1][2]);
	printf("[%c] = [%c]\n", tab[2][0], tab[2][2]);

	printf("\n---------------------\n");
	printf("ft_memcpy:\n");
	char dst[50] = "Sal";
	char src1[10] = "ut, ";
	char src2[10] = "ca va ?";
	char src3[10] = "";
	printf("[%s]\n", ft_memcpy(dst, dst, 1));
	printf("[%s]\n", ft_memcpy(dst, src1, 0));
	printf("[%s]\n", ft_memcpy(dst, src2, 1));
	printf("[%s]\n", ft_memcpy(dst, src2, 5));
	printf("[%s]\n", ft_memcpy(dst, src3, 3));


	printf("\n---------------------\n");
	printf("ft_strdup:\n");
	printf("[%s]\n", ft_strdup("Yo"));
	printf("[%s]\n", ft_strdup(""));
	printf("[%s]\n", ft_strdup(NULL));
	printf("[%s]\n", ft_strdup("CA MARCHE ?"));

	printf("\n---------------------\n");
	printf("BONUS");	
	printf("\n---------------------\n\n");

	/*
	printf("ft_isupper:\n");
	printf("0 = %d\n", ft_isupper(0));
	printf("'A' = %d\n", ft_isupper('A'));
	printf("'a' = %d\n", ft_isupper('a'));	
	printf("'8' = %d\n", ft_isupper('8'));

	printf("\n---------------------\n");
	printf("ft_islower:\n");
	printf("0 = %d\n", ft_islower(0));
	printf("'A' = %d\n", ft_islower('A'));
	printf("'a' = %d\n", ft_islower('a'));	
	printf("'8' = %d\n", ft_islower('8'));
	*/

	printf("\n---------------------\n");	
	printf("ft_strnew:\n");
	printf("[%s]\n", ft_memset(ft_strnew(0), '1', 0));
	printf("[%s]\n", ft_memset(ft_strnew(10), '2', 10));
	printf("[%s]\n", ft_memset(ft_strnew(20), '3', 20));

	/*
	printf("\n---------------------\n");
	printf("ft_abs:\n");
	printf("0 = %d\n", ft_abs(0));
	printf("-10 = %d\n", ft_abs(-10));
	printf("-0 = %d\n", ft_abs(-0));	
	printf("15 = %d\n", ft_abs(15));
	printf("-4242 = %d\n", ft_abs(-4242));
	printf("-123 = %d\n", ft_abs(-123));
	printf("123 = %d\n", ft_abs(123));
	*/

	/*
	printf("\n---------------------\n");
	printf("ft_strclr:\n");
	char clr1[15] = "Je test";
	char clr2[15] = "";
	char clr3[25] = "Précédent était vide.";

	printf("Avant le ft_strclr:\n");
	printf("clr1: [%s]\n", clr1);
	printf("clr2: [%s]\n", clr2);
	printf("clr3: [%s]\n", clr3);

	ft_strclr(clr1);
	ft_strclr(clr2);
	ft_strclr(clr3);

	printf("\nAprès le ft_strclr:\n");
	printf("clr1: [%s]\n", clr1);
	printf("clr2: [%s]\n", clr2);
	printf("clr3: [%s]\n", clr3);
*/
	return (0);
}
