/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:52:15 by meharuty          #+#    #+#             */
/*   Updated: 2026/04/13 14:52:18 by meharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_free_stacks(t_ps *ps)
{
	free_stack(&ps->a);
	free_stack(&ps->b);
}

static int	ps_boot(int argc, char **argv, t_ps *ps, double *disorder)
{
	int	ret;

	ps->print_ops = 1;
	ret = parse_args(argc, argv, ps);
	if (ret == 0)
		return (0);
	if (ret < 0)
	{
		ps_free_stacks(ps);
		error_exit();
	}
	*disorder = compute_disorder(ps->a);
	if (is_sorted(ps->a))
	{
		ps->strategy_name = "already_sorted";
		ps->complexity = "O(1)";
	}
	else
		run_strategy(ps, *disorder);
	if (ps->bench)
		print_bench(ps, *disorder);
	ps_free_stacks(ps);
	return (1);
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	double	disorder;

	if (argc < 2)
		return (0);
	ps = (t_ps){0};
	ps_boot(argc, argv, &ps, &disorder);
	return (0);
}
