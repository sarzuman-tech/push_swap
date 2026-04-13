/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies_rank.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:01:38 by meharuty          #+#    #+#             */
/*   Updated: 2026/04/13 15:03:06 by meharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rank_copy_contents(t_list *a, long *vals)
{
	t_list	*c;
	int		i;

	c = a;
	i = 0;
	while (c)
	{
		vals[i++] = c->content;
		c = c->next;
	}
}

static int	rank_for_idx(long *vals, int n, int idx)
{
	int	j;
	int	rank;

	rank = 0;
	j = 0;
	while (j < n)
	{
		if (vals[j] < vals[idx])
			rank++;
		j++;
	}
	return (rank);
}

static void	rank_apply(t_list *a, long *vals, int n)
{
	t_list	*c;
	int		idx;

	c = a;
	idx = 0;
	while (c)
	{
		c->content = rank_for_idx(vals, n, idx);
		c = c->next;
		idx++;
	}
}

void	assign_ranks(t_list *a)
{
	int		n;
	long	*vals;

	n = ft_lstsize_ps(a);
	if (n == 0)
		return ;
	vals = malloc(sizeof(long) * n);
	if (!vals)
		return ;
	rank_copy_contents(a, vals);
	rank_apply(a, vals, n);
	free(vals);
}
