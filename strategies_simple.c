#include "push_swap.h"

static int	find_min_index(t_list *a)
{
	int		i;
	int		min_i;
	long	min_v;
	t_list	*c;

	i = 0;
	min_i = 0;
	if (!a)
		return (0);
	min_v = a->content;
	c = a;
	while (c)
	{
		if (c->content < min_v)
		{
			min_v = c->content;
			min_i = i;
		}
		i++;
		c = c->next;
	}
	return (min_i);
}

static void	simple_rotate_min(t_ps *ps, int idx, int sz)
{
	int	i;

	if (idx <= sz / 2)
	{
		i = 0;
		while (i++ < idx)
			ps_ra(ps);
	}
	else
	{
		i = 0;
		while (i++ < sz - idx)
			ps_rra(ps);
	}
}

void	strategy_simple(t_ps *ps)
{
	int	idx;
	int	sz;

	while (ps->a)
	{
		sz = ft_lstsize_ps(ps->a);
		idx = find_min_index(ps->a);
		simple_rotate_min(ps, idx, sz);
		ps_pb(ps);
	}
	while (ps->b)
		ps_pa(ps);
}
