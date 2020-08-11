#include <stdio.h>

char *ft_strstr(char *a, char *b);

int main()
{	
	char *a;
	char *b;
	a = "1234567890";
	b = "67890";
	
	printf("%s\n",ft_strstr(a,b));
	a = "6789012345";
	b = "8";
	
	printf("%s\n",ft_strstr(a,b));
	return 0;
}
