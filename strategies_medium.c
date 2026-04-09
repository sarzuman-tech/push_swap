#include "push_swap.h"
#include <math.h>

static int	find_max_index(t_list *b)
{
	int		i;
	int		max_i;
	long	max_v;
	t_list	*c;

	i = 0;
	max_i = 0;
	if (!b)
		return (0);
	max_v = b->content;
	c = b;
	while (c)
	{
		if (c->content > max_v)
		{
			max_v = c->content;
			max_i = i;
		}
		i++;
		c = c->next;
	}
	return (max_i);
}

static void	medium_spin_max(t_ps *ps, int m, int n)
{
	int	i;

	if (m <= n / 2)
	{
		i = 0;
		while (i++ < m)
			ps_rb(ps);
	}
	else
	{
		i = 0;
		while (i++ < n - m)
			ps_rrb(ps);
	}
}

static void	medium_push_phase(t_ps *ps, int chunk, int *limit)
{
	while (ps->a)
	{
		if (ps->a->content <= *limit)
		{
			ps_pb(ps);
			if (ps->b && ps->b->next
				&& ps->b->content < *limit - (chunk / 2))
				ps_rb(ps);
			(*limit)++;
		}
		else
			ps_ra(ps);
	}
}

void	strategy_medium(t_ps *ps)
{
	int	n;
	int	chunk;
	int	limit;
	int	m;

	n = ft_lstsize_ps(ps->a);
	if (n <= 10)
	{
		strategy_simple(ps);
		return ;
	}
	chunk = (int)sqrt((double)n);
	if (chunk < 1)
		chunk = 1;
	limit = chunk;
	medium_push_phase(ps, chunk, &limit);
	while (ps->b)
	{
		m = find_max_index(ps->b);
		n = ft_lstsize_ps(ps->b);
		medium_spin_max(ps, m, n);
		ps_pa(ps);
	}
}
