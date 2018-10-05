#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	ft_isalpha(char s);
void  bzero(void *s, size_t n);
int	ft_toupper(int c);
size_t	ft_strlen(char *s);
void *ft_memset(void *b, int c, size_t len);
void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
char *ft_strdup(const char *s1);
char *ft_strcat(char *restrict s1, const char *restrict s2);
int puts(const char *s);
void ft_cat(int fd);
size_t ft_index_fmatch(char *str, char match);
size_t ft_index_lmatch(char *str, char match);
void *ft_memalloc(size_t size);
char *ft_strnew(size_t size);

int iteration = 200;

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
		real = memcpy(real, strr, 10);
		my = ft_memcpy(my, strr, 10);
		if (strcmp(my, real) != 0)
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
	
	return (0);
}
