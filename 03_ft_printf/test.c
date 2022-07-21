#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
	int a = printf("%-5.0d\n", 0);
	int b = ft_printf("%-5.0d\n", 0);

	printf("%d \n", a);
	printf("%d \n", b);
	return (0);
}
