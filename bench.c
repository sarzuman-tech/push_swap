/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:20:18 by sarzuman          #+#    #+#             */
/*   Updated: 2026/04/13 15:20:19 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bn_putn(int n)
{
	char	c;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(2, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		bn_putn((int)(nb / 10));
	c = '0' + (nb % 10);
	write(2, &c, 1);
}

static const char	*bn_opnm(t_op op)
{
	static const char	*nm[OP_COUNT] = {
		"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"
	};

	return (nm[op]);
}

static void	bn_disorder(double disorder)
{
	int	p;

	p = (int)(disorder * 10000.0 + 0.5);
	write(2, "[bench] disorder: ", 18);
	bn_putn(p / 100);
	write(2, ".", 1);
	if (p % 100 < 10)
		write(2, "0", 1);
	bn_putn(p % 100);
	write(2, "%\n", 2);
}

static void	bn_ops_lines(t_ps *ps)
{
	int	i;

	write(2, "[bench] operations: ", 20);
	bn_putn((int)ps->total_ops);
	write(2, "\n", 1);
	i = 0;
	while (i < OP_COUNT)
	{
		write(2, "[bench] ", 8);
		write(2, bn_opnm((t_op)i), ft_strlen(bn_opnm((t_op)i)));
		write(2, ": ", 2);
		bn_putn((int)ps->op_count[i]);
		write(2, "\n", 1);
		i++;
	}
}

void	print_bench(t_ps *ps, double disorder)
{
	bn_disorder(disorder);
	write(2, "[bench] strategy: ", 18);
	write(2, ps->strategy_name, ft_strlen(ps->strategy_name));
	write(2, " (", 2);
	write(2, ps->complexity, ft_strlen(ps->complexity));
	write(2, ")\n", 2);
	bn_ops_lines(ps);
}
