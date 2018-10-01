#include <unistd.h>
#include <stdio.h>
int	ft_isalpha(char s);
void  bzero(void *s, size_t n);
int	ft_toupper(int c);
size_t	ft_strlen(char *s);
void *
     ft_memset(void *b, int c, size_t len);

	 void *
	      memcpy(void *restrict dst, const void *restrict src, size_t n);
		char *
		     ft_strdup(const char *s1);

int main()
{
	char s = 'a';
	//char string[] = "Bonjou\n";
	char string[] = "abc";
	char str[10];

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
	return (0);
}
