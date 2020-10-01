#include <stdio.h>

int	ft_is_prime(int a);

int main()
{
	printf("-1 %d  \n" , ft_is_prime(-1));
	printf("2 %d\n", ft_is_prime(2));
	printf("2147483647 %d\n" , ft_is_prime(2147483647));
}
