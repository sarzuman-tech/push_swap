#include "ft_printf.h"

void ft_print_double(double n)
{
	int k;
	double p;

	k = (int)n;
	p = (n * 100) - ((double)k * 100);
	ft_printnbr(k);
	if (p > 0)
	{
		write(1, ".", 1);
		ft_printnbr(p + 0.5);
	}
}