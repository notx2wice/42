#include <stdio.h>

int ft_strncmp(char *a, char *b ,unsigned int n);

int main()
{
	char * a;
	char * b;
	a = "aaaa";
	b = "aaab";

	printf("%d   " ,ft_strncmp(a,b,3));
	printf("%d   " ,ft_strncmp(a,b,4));
	return 0;
}
