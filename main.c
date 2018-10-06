#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "includes/libfts.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int iteration = 2000; // nb of iteration for memalloc, strdup, strnew

int test_memset(char **str, int i)
{
	int len;
	int ret = 1;
	char *cmp;
	while (--i >= 0)
	{
		len = ft_strlen(str[i]);
		len = rand() % len;
		cmp = ft_strdup(str[i]);
		ft_memset(str[i], 'b', len);
		memset(cmp, 'b', len);
		if ((ft_index_lmatch(str[i], 'b') == len - 1) &&
			(str[i][ft_index_lmatch(str[i], 'b') + 1] == 'a') &&
			strcmp(str[i], cmp) == 0)
				printf(".");
		else
		{
			printf("x");
			ret = 0;
		}
	}
	printf("\n");
	return (ret);
}

int test_rand_strnew()
{
	char *newstr[iteration];
	int i = 0;
	int r = 0;
	printf("Allocation tests : ");
	while (i < iteration)
	{
		r = (rand() % 2000) + 1;
		newstr[i] = ft_strnew(r);
		int j = -1;
		while (++j < r)
		{
			newstr[i][j] = 'a';
		}
		printf(".");
		i++;
	}

	printf("\n***************\nTesting ft_memset\n");
	if (test_memset(newstr, i))
		printf("ft_memset [OK]\n");
	else
		printf("ft_memset [FAIL]\n");

	i = -1;
	printf("\nFree tests : ");
	while (++i < iteration)
	{
		printf(".");
		free(newstr[i]);
	}
	printf("\n");
	return (1);
}

int test_rand_memalloc()
{
	char *newstr[iteration];
	int i = 0;
	int r = 0;
	printf("Allocation tests : ");
	while (i < iteration)
	{
		r = (rand() % 2000) + 1;
		newstr[i] = ft_memalloc(r);
		int j = -1;
		while (++j < r)
		{
			newstr[i][j] = 'a';
		}
		printf(".");
		i++;
	}
	i = -1;
	printf("\nFree tests : ");
	while (++i < iteration)
	{
		printf(".");
		free(newstr[i]);
	}
	printf("\n");
	return (1);
}

int	test_isalpha()
{
	unsigned char c = 0;
	int ret = 1;
	while (c <= 127)
	{
		int is = 0;
		int real = 0;
		is = ft_isalpha(c);
		real = isalpha(c);
		
		if (is != real)
		{
			printf("\nft_isalpha : ");
			if (is)
				printf("YES | ");
			else
				printf("NO | ");
			printf("isalpha : ");
			if (real)
				printf("YES\n");
			else
				printf("NO\n");
			ret = 0;
		} else
			printf(".");
		c++;
	}
	printf("\n");
	return (ret);
}

int	test_isdigit()
{
	unsigned char c = 0;
	int ret = 1;
	while (c <= 127)
	{
		int is = 0;
		int real = 0;
		is = ft_isdigit(c);
		real = isdigit(c);
		if (is != real)
		{
			printf("\nft_isalpha : ");
			if (is)
				printf("YES | ");
			else
				printf("NO | ");
			printf("isalpha : ");
			if (real)
				printf("YES\n");
			else
				printf("NO\n");
			ret = 0;
		} else
			printf(".");
		c++;
	}
	printf("\n");
	return (ret);
}

int	test_isprint()
{
	unsigned char c = 0;
	int ret = 1;
	while (c <= 127)
	{
		int is = 0;
		int real = 0;
		is = ft_isprint(c);
		real = isprint(c);
		if (is != real)
		{
			printf("\nft_isalpha : ");
			if (is)
				printf("YES | ");
			else
				printf("NO | ");
			printf("isalpha : ");
			if (real)
				printf("YES\n");
			else
				printf("NO\n");
			ret = 0;
		} else
			printf(".");
		c++;
	}
	printf("\n");
	return (ret);
}

int	test_isalnum()
{
	unsigned char c = 0;
	int ret = 1;
	while (c <= 127)
	{
		int is = 0;
		int real = 0;
		is = ft_isalnum(c);
		real = isalnum(c);
		if (is != real)
		{
			printf("\nft_isalpha : ");
			if (is)
				printf("YES | ");
			else
				printf("NO | ");
			printf("isalpha : ");
			if (real)
				printf("YES\n");
			else
				printf("NO\n");
			ret = 0;
		} else
			printf(".");
		c++;
	}
	printf("\n");
	return (ret);
}

int test_tolower()
{
	unsigned char c = 0;
	int ret = 1;
	while (c <= 127)
	{
		int is = 0;
		int real = 0;
		is = ft_tolower(c);
		real = tolower(c);
		if (is != real)
		{
			printf("\nft_isalpha : ");
			if (is)
				printf("YES | ");
			else
				printf("NO | ");
			printf("isalpha : ");
			if (real)
				printf("YES\n");
			else
				printf("NO\n");
			ret = 0;
		} else
			printf(".");
		c++;
	}
	printf("\n");
	return (ret);
}

int test_toupper()
{
	unsigned char c = 0;
	int ret = 1;
	while (c <= 127)
	{
		int is = 0;
		int real = 0;
		is = ft_toupper(c);
		real = toupper(c);
		if (is != real)
		{
			printf("\nft_isalpha : ");
			if (is)
				printf("YES | ");
			else
				printf("NO | ");
			printf("isalpha : ");
			if (real)
				printf("YES\n");
			else
				printf("NO\n");
			ret = 0;
		} else
			printf(".");
		c++;
	}
	printf("\n");
	return (ret);
}

int	test_strdup()
{
	char *my;
	char *real;
	int ret = 1;
	char *strings[] = {
		"a",
		"ab",
		"test",
		"asl;dasl;jklskdfakfsdlkfjskjaljkslsalksjsfjdklsljf",
		""
	};

	int i = 0;
	while (i < 5)
	{
		real = strdup(strings[i]);
		my = ft_strdup(strings[i]);
		if (strcmp(my, real) != 0)
		{
			printf("real : '%s'\n", real);
			printf("my : '%s'\n", my);
			printf("\nft_strdup diff on '%s'\n", strings[i]);
			ret = 0;
		}
		else
			printf(".");
		free(real);
		free(my);
		printf(".");
		i++;
	}
	printf("\n");
	return (ret);
}

int	test_memcpy()
{
	char *my;
	char *real;
	int ret = 1;
	char strr[] = "a;sdlkfjasd;flkjasd;flkjasdf;lkjasdf;lkjasdf;lkjasdf";

	int i = 0;
	while (i < 5)
	{
		real = ft_strnew(strlen(strr));
		my = ft_strnew(strlen(strr));
		int s = rand() % 15;
		real = memcpy(real, strr, s);
		my = ft_memcpy(my, strr, s);
		if (memcmp(my, real, s) != 0)
		{
			printf("real : '%s'\n", real);
			printf("my : '%s'\n", my);
			ret = 0;
		}
		else
			printf(".");
		i++;
	}
	printf("\n");
	return (ret);
}

int	test_strlen()
{
	size_t my;
	size_t real;
	int ret = 1;
	char *strings[] = {
		"a",
		"ab",
		"test",
		"asl;dasl;jklskdfakfsdlkfjskjaljkslsalksjsfjdklsljf",
		""
	};

	int i = 0;
	while (i < 5)
	{
		real = strlen(strings[i]);
		my = ft_strlen(strings[i]);
		if (my != real)
		{
			printf("\nft_strlen diff on %s\n", strings[i]);
			ret = 0;
		}
		else
			printf(".");
		i++;
	}
	printf("\n");
	return (ret);
}

int test_bzero()
{
	char *one = ft_strdup("dfsa;lksjd;aslksklasslfsaljkfsa;jsfadjkl");
	char *one2 = ft_strdup("dfsa;lksjd;aslksklasslfsaljkfsa;jsfadjkl");
	char *two = ft_strdup("df");
	char *two2 = ft_strdup("df");
	char *three = ft_strdup("d");
	char *three2 = ft_strdup("d");
	char *four = ft_strdup("");
	char *four2 = ft_strdup("");
	int ret = 1;

	size_t len;
	len = ft_strlen(one) - 10;
	ft_bzero(one, len);
	bzero(one2, len);
	if (memcmp(one, one2, len) == 0)
		printf(".");
	else 
	{
		ret = 0;
		printf("x");
	}
	len = ft_strlen(two);
	ft_bzero(two, len);
	bzero(two2, len);
	if (memcmp(two, two2, len) == 0)
		printf(".");
	else 
	{
		ret = 0;
		printf("x");
	}
	len = ft_strlen(three);
	ft_bzero(three, len);
	bzero(three2, len);
	if (memcmp(three, three2, len) == 0)
		printf(".");
	else 
	{
		ret = 0;
		printf("x");
	}
	len = ft_strlen(four);
	ft_bzero(four, len);
	bzero(four2, len);
	if (memcmp(four, four2, len) == 0)
		printf(".");
	else 
	{
		ret = 0;
		printf("x");
	}
	printf("\n");
	 return (ret);
}

int test_puts()
{
	printf("Visual diff /!\\ :\n");
	printf("*** REAL ***\n");
	puts("");
	printf("***  FT  ***\n");
	ft_puts("");
	printf("*** REAL ***\n");
	puts("Bonjour");
	printf("***  FT  ***\n");
	ft_puts("Bonjour");
	printf("*** REAL ***\n");
	puts(NULL);
	printf("***  FT  ***\n");
	ft_puts(NULL);
	return (1);
}

int test_strcat()
{
	int ret = 1;

	char *test = ft_strnew(20);
	char *test2 = ft_strnew(20);

	test = ft_strcat(test, "Bonjour");
	test2 = ft_strcat(test2, "Bonjour");

	if (strcmp(test, test2) == 0)
		printf(".");
	else
	{
		printf("x");
		ret = 0;
	}
	test = ft_strcat(test, "");
	test2 = ft_strcat(test2, "");

	if (strcmp(test, test2) == 0)
		printf(".");
	else
	{
		printf("x");
		ret = 0;
	}
	test = ft_strcat(test, "Bonjour");
	test2 = ft_strcat(test2, "Bonjour");

	if (strcmp(test, test2) == 0)
		printf(".");
	else
	{
		printf("x");
		ret = 0;
	}
	test = ft_strcat(test, "Bonjou");
	test2 = ft_strcat(test2, "Bonjou");

	if (strcmp(test, test2) == 0)
		printf(".");
	else
	{
		printf("x");
		ret = 0;
	}
	test = ft_strcat(test, "r");
	test2 = ft_strcat(test2, "r");

	if (strcmp(test, test2) == 0)
		printf(".");
	else
	{
		printf("x");
		ret = 0;
	}
	printf("\n");
	return (ret);
}

int test_cat()
{
	printf("\ntesting stdin (CTRL + D to end)\n");
	ft_cat(0);
	printf("\ntesting -42\n");
	ft_cat(-42);
	printf("\ntesting 42\n");
	ft_cat(42);
	printf("\ntesting on a file (libfts.a)\n");
	ft_cat(open("libfts.a", O_RDONLY));
	return (1);
}

int test_strstr()
{
	char *strings[] = {
		"Test numero 1",
		"2eme test qui s'affiche a partir d'ici",
		"Bonjour",
		"a",
		"ab",
		""
	};
	char *search[] = {
		"numero",
		"ici",
		"devrait retourner null",
		"a",
		"b",
		""
	};

	int i = 0;
	int ret = 1;
	char *me;
	char *real;

	while (i < 6)
	{
		me = ft_strstr(strings[i], search[i]);
		real = strstr(strings[i], search[i]);
		if ((me == NULL && real == NULL) || strcmp(me, real) == 0)
		{
			printf(".");
		}
		else
		{
			ret = 0;
			printf("x");
		}
		i++;
	}

	printf("\n");
	return (ret);
}

int test_fmatch()
{
	char *strings[] = {
		"Test numero 1",
		"2eme test",
		"Bonjour",
		NULL,
		"ab",
		""
	};
	int ret = 1;
	char *search = "neyhat";
	int rets[] = {5, 1, -1, -1, 0, -1};
	int i = 0;

	while (i < 6)
	{
		if (ft_index_fmatch(strings[i], search[i]) == rets[i])
			printf(".");
		else
		{
			ret = 0;
			printf("x");
		}
		i++;
	}
	printf("\n");
	return (ret);
}

int test_lmatch()
{
	char *strings[] = {
		"Test numero 1",
		"2eme test",
		"Bonjour",
		NULL,
		"ab",
		""
	};
	int ret = 1;
	char *search = "neyhat";
	int rets[] = {5, 6, -1, -1, 0, -1};
	int i = 0;

	while (i < 6)
	{
		if (ft_index_lmatch(strings[i], search[i]) == rets[i])
			printf(".");
		else
		{
			ret = 0;
			printf("x");
		}
		i++;
	}
	printf("\n");
	return (ret);
}

int main(void)
{
	printf("***************\nTesting ft_strnew\n");
	if (test_rand_strnew())
		printf("ft_strnew [OK]\n");
	printf("***************\nTesting ft_memalloc\n");
	if (test_rand_memalloc())
		printf("ft_memalloc [OK]\n");
	printf("***************\nTesting ft_isalpha\n");
	if (test_isalpha())
		printf("ft_isalpha [OK]\n");
	else
		printf("ft_isalpha [FAIL]\n");

	printf("***************\nTesting ft_isdigit\n");
	if (test_isdigit())
		printf("ft_isdigit [OK]\n");
	else
		printf("ft_isdigit [FAIL]\n");

	printf("***************\nTesting ft_isprint\n");
	if (test_isprint())
		printf("ft_isprint [OK]\n");
	else
		printf("ft_isprint [FAIL]\n");

	printf("***************\nTesting ft_isalnum\n");
	if (test_isalnum())
		printf("ft_isalnum [OK]\n");
	else
		printf("ft_isalnum [FAIL]\n");
	printf("***************\nTesting ft_tolower\n");
	if (test_tolower())
		printf("ft_tolower [OK]\n");
	else
		printf("ft_tolower [FAIL]\n");
	printf("***************\nTesting ft_toupper\n");
	if (test_toupper())
		printf("ft_toupper [OK]\n");
	else
		printf("ft_toupper[FAIL]\n");
	printf("***************\nTesting ft_strlen\n");
	if (test_strlen())
		printf("ft_strlen [OK]\n");
	else
		printf("ft_strlen [FAIL]\n");

	printf("***************\nTesting ft_memcpy\n");
	if (test_memcpy())
		printf("ft_memcpy [OK]\n");
	else
		printf("ft_memcpy [FAIL]\n");
	printf("***************\nTesting ft_strdup\n");
	if (test_strdup())
		printf("ft_strdup [OK]\n");
	else
		printf("ft_strdup [FAIL]\n");

	printf("***************\nTesting ft_bzero\n");
	if (test_bzero())
		printf("ft_bzero [OK]\n");
	else
		printf("ft_bzero [FAIL]\n");
	
	printf("***************\nTesting ft_puts\n");
	if (test_puts())
		printf("ft_puts [OK]\n");
	else
		printf("ft_puts [FAIL]\n");
	printf("***************\nTesting ft_strcat\n");
	if (test_strcat())
		printf("ft_strcat [OK]\n");
	else
		printf("ft_strcat [FAIL]\n");
	printf("***************\nTesting ft_strstr\n");
	if (test_strstr())
		printf("ft_strstr [OK]\n");
	else
		printf("ft_strstr [FAIL]\n");
	printf("***************\nTesting ft_index_fmatch\n");
	if (test_fmatch())
		printf("ft_index_fmatch [OK]\n");
	else
		printf("ft_index_fmatch [FAIL]\n");
	printf("***************\nTesting ft_index_lmatch\n");
	if (test_lmatch())
		printf("ft_index_lmatch [OK]\n");
	else
		printf("ft_index_lmatch [FAIL]\n");
	printf("***************\nTesting ft_cat\n");
	if (test_cat())
		printf("ft_cat [OK]\n");
	else
		printf("ft_cat [FAIL]\n");
	return (0);
}
