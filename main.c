#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	ft_isalpha(char s);
void  bzero(void *s, size_t n);
int	ft_toupper(int c);
size_t	ft_strlen(char *s);
void *ft_memset(void *b, int c, size_t len);
void *ft_memcpy(void *dst, const void *src, size_t n);
char *ft_strdup(const char *s1);
char *ft_strcat(char *restrict s1, const char *restrict s2);
int puts(const char *s);
void ft_cat(int fd);
size_t ft_index_fmatch(char *str, char match);
size_t ft_index_lmatch(char *str, char match);
void *ft_memalloc(size_t size);
char *ft_strnew(size_t size);
char *ft_strstr(char *s1, char *s2);

int iteration = 200;

int test_memset(char **str, int i)
{
	size_t len;
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
		//printf("length %d\n", r);
		//	printf("pass new\n");
		newstr[i] = ft_strnew(r);
		//	printf("end new\n");
		int j = -1;
		while (++j < r)
		{
			newstr[i][j] = 'a';
		}
		//printf("%s\n", newstr[i]);
		//printf("end iteration\n");
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
		//printf("freeing newstr[%d]\n", i);
		//
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
		//printf("length %d\n", r);
		//	printf("pass new\n");
		newstr[i] = ft_memalloc(r);
		//	printf("end new\n");
		int j = -1;
		while (++j < r)
		{
			newstr[i][j] = 'a';
		}
		//printf("%s\n", newstr[i]);
		//printf("end iteration\n");
		printf(".");
		i++;
	}
	i = -1;
	printf("\nFree tests : ");
	while (++i < iteration)
	{
		//printf("freeing newstr[%d]\n", i);
		//
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
			//printf("testing : %c\n", c);
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
		/*
		printf("testing : %c\n", c);
		printf("ft_isdigit : ");
		if (is)
			printf("YES | ");
		else
			printf("NO | ");
		printf("isdigit : ");
		if (is)
			printf("YES\n");
		else
			printf("NO\n");
		*/
		if (is != real)
		{
			//printf("testing : %c\n", c);
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
		/*
		printf("testing : %c\n", c);
		printf("ft_isprint : ");
		if (is)
			printf("YES | ");
		else
			printf("NO | ");
		printf("isprint : ");
		if (is)
			printf("YES\n");
		else
			printf("NO\n");
			*/
		if (is != real)
		{
			//printf("testing : %c\n", c);
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
		/*
		printf("testing : %c\n", c);
		printf("ft_isalnum : ");
		if (is)
			printf("YES | ");
		else
			printf("NO | ");
		printf("isalnum : ");
		if (is)
			printf("YES\n");
		else
			printf("NO\n");
			*/
		if (is != real)
		{
			//printf("testing : %c\n", c);
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
		/*
		printf("testing : %c\n", c);
		printf("ft_tolower : ");
		if (is)
			printf("YES | ");
		else
			printf("NO | ");
		printf("tolower : ");
		if (is)
			printf("YES\n");
		else
			printf("NO\n");
			*/
		if (is != real)
		{
			//printf("testing : %c\n", c);
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
		/*
		printf("testing : %c\n", c);
		printf("ft_toupper : ");
		if (is)
			printf("YES | ");
		else
			printf("NO | ");
		printf("toupper : ");
		if (is)
			printf("YES\n");
		else
			printf("NO\n");
			*/
		if (is != real)
		{
			//printf("testing : %c\n", c);
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
	char *str;
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
	char *str;
	char *my;
	char *real;
	int ret = 1;
	/*char *strings[] = {
		"a",
		"ab",
		"test",
		"asl;dasl;jklskdfakfsdlkfjskjaljkslsalksjsfjdklsljf",
		""
	};
	*/
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
			//printf("\nft_strdup diff on '%s'\n", strings[i]);
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
	char *str;
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
	printf("\ntesting on a file (libfts.a)\n");
	ft_cat(open("libfts.a", O_RDONLY));
	return (1);
}

int test_strstr()
{
	char *s = "Bonjour je suis conent";

	printf("%s\n", ft_strstr(s, "Bonjour"));
	printf("\n");
	return (1);
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
	printf("***************\nTesting ft_cat\n");
	if (test_cat())
		printf("ft_cat [OK]\n");
	else
		printf("ft_cat [FAIL]\n");
	printf("***************\nTesting ft_strstr\n");
	if (test_strstr())
		printf("ft_strstr [OK]\n");
	else
		printf("ft_strstr [FAIL]\n");

	return (0);
}
