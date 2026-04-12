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

void	strategy_simple_3_hardcode(t_ps *ps)
{
	int	idx;

	idx = find_min_index(ps->a);
	if (idx == 1)
		ps_ra(ps);
	else if (idx == 2)
		ps_rra(ps);
	ps_pb(ps);
	if (ps->a->content > ps->a->next->content)
		ps_sa(ps);
	ps_pa(ps);
}

void	strategy_simple(t_ps *ps)
{
	int	idx;
	int	sz;

	sz = ft_lstsize_ps(ps->a);
	if (sz == 3)
		strategy_simple_3_hardcode(ps);
	else
	{
		while (ps->a)
		{
			idx = find_min_index(ps->a);
			simple_rotate_min(ps, idx, sz);
			ps_pb(ps);
		}
		while (ps->b)
			ps_pa(ps);
	}
}
