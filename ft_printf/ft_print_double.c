#include "ft_printf.h"

void ft_print_double(double n)
{
    int i;
    int k;
    double p;

    i = 0;
    k = (int)n;
    p = (n * 100) - ((double)k * 100);
    printf("%lf\n",p);
    ft_printnbr(k);
    if (p > 0)
    {
        write(1, ".", 1);
        ft_printnbr(p);
    }
}