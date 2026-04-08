#include "push_swap.h"

static void	count_pairs_from(t_list *i, long *m, long *t)
{
	t_list	*j;

	j = i->next;
	while (j)
	{
		(*t)++;
		if (i->content > j->content)
			(*m)++;
		j = j->next;
	}
}

double	compute_disorder(t_list *a)
{
	t_list	*i;
	long	mistakes;
	long	total;

	mistakes = 0;
	total = 0;
	i = a;
	while (i)
	{
		count_pairs_from(i, &mistakes, &total);
		i = i->next;
	}
	if (total == 0)
		return (0.0);
	return ((double)mistakes / (double)total);
}

int	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}
