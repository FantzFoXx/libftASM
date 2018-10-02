#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	ft_isalpha(char s);
void  bzero(void *s, size_t n);
int	ft_toupper(int c);
size_t	ft_strlen(char *s);
void *ft_memset(void *b, int c, size_t len);
void *memcpy(void *restrict dst, const void *restrict src, size_t n);
char *ft_strdup(const char *s1);
char *ft_strcat(char *restrict s1, const char *restrict s2);
int puts(const char *s);
void ft_cat(int fd);


int main()
{
	char s = 'a';
	//char string[] = "Bonjou\n";
	char string[] = "abc";
	char string1[] = "this mdr is ";
	char string2[] = "a ptdr string";
	char str[10];
	int	fd = open("lorem", O_RDONLY);

	if (ft_isalpha(s))
		printf("YES\n");fflush(stdout);

	write(1, string, 8);fflush(stdout);
	//ft_bzero(string, strlen(string));fflush(stdout);
	//write(1, string, 8);fflush(stdout);
	write(1, "\n", 1);fflush(stdout);
	s = ft_toupper(s);fflush(stdout);
	write(1, &s, 1);fflush(stdout);
	printf("%d\n", ft_toupper(s));fflush(stdout);
	printf("len %d\n", ft_strlen(string));fflush(stdout);
	ft_memset(str, 0, 10);fflush(stdout);
	printf(ft_memset(str, 'a', 9));fflush(stdout);
	printf(str);fflush(stdout);
	ft_memcpy(str, string, 3);fflush(stdout);
	printf("\n");fflush(stdout);
	printf("str %s\n", str);fflush(stdout);
	char *dup = ft_strdup(str);
	//ft_bzero(dup, ft_strlen(str));
	printf("dup : %s\n", dup);
	char *cat = malloc(ft_strlen(string1) + ft_strlen(string2) + 1);
	ft_bzero(cat, ft_strlen(string1) + ft_strlen(string2) + 1);
	ft_memcpy(cat, string1);
	//ft_strcat(cat, string2);
	printf("addr :%p\n", cat);
	printf("ret cat : %p\n", ft_strcat(cat, string2));
	printf("cat : %s\n", cat);
	printf("ft_puts return : %d\n", ft_puts("Bonjour ! haha"));fflush(stdout);
	printf("puts return : %d\n", puts("Bonjour ! haha"));fflush(stdout);
	printf("ft_puts return : %d\n", ft_puts(0));fflush(stdout);
	printf("puts return : %d\n", puts(0));fflush(stdout);
	//printf("\n---------------\n");
	//printf("ft_puts return : %d\n", ft_puts(""));fflush(stdout);
	printf("\n---------------\n");
	//printf("puts return : %d", puts(""));fflush(stdout);
	//ft_puts("");
	printf("ft_puts return : %d\n", ft_puts(""));fflush(stdout);
	printf("---------------\n");
	printf("fd : %d\n", fd);
	ft_cat(0);
	ft_cat(fd);
	return (0);
}
