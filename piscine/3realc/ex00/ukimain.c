#include <string.h>
#include <stdio.h>

int	ft_strcmp(char *a, char *b);

int		main()
{
	char * a;
	char * b;
	a = "ABCDE";
	b = "ABCDE";
	int t;
	printf("%d   " ,t =  ft_strcmp(a,b));

	a = "ABC";
	b = "ABCD";
	printf("%d   " ,t = ft_strcmp(a,b));

	a = "abc";
	b = "ABC";
	printf("%d   ", t = ft_strcmp(a,b));
	return 0;
}
