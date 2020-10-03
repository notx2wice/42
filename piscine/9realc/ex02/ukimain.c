#include <stdio.h>

char **ft_split(char *str, char *charset);

int main(int argc , char **argv)
{
	char **a = ft_split(argv[1] , argv[2]);
	for(int i = 0; i < 11111; i++)
	{
		if(a[i] == 0)
			break;
		printf("[%s]\n", a[i]);
	}
}

