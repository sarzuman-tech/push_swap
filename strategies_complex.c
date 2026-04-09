#include "push_swap.h"

static void	complex_bit_pass(t_ps *ps, int bit_i, int n)
{
	int	j;

	j = 0;
	while (j < n)
	{
		if (((ps->a->content >> bit_i) & 1) == 0)
			ps_pb(ps);
		else
			ps_ra(ps);
		j++;
	}
	while (ps->b)
		ps_pa(ps);
}

void	strategy_complex(t_ps *ps)
{
	int	max_bits;
	int	i;
	int	n;

	n = ft_lstsize_ps(ps->a);
	if (n <= 10)
	{
		strategy_simple(ps);
		return ;
	}
	max_bits = 0;
	while (((n - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		complex_bit_pass(ps, i, n);
		i++;
	}
}
