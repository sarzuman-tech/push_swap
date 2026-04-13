/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies_run.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:24:22 by sarzuman          #+#    #+#             */
/*   Updated: 2026/04/13 15:24:23 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	go_simple_labeled(t_ps *ps)
{
	ps->strategy_name = "simple";
	ps->complexity = "O(n^2)";
	strategy_simple(ps);
}

static void	go_medium_labeled(t_ps *ps)
{
	assign_ranks(ps->a);
	ps->strategy_name = "medium";
	ps->complexity = "O(n*sqrt(n))";
	strategy_medium(ps);
}

static void	go_complex_labeled(t_ps *ps)
{
	assign_ranks(ps->a);
	ps->strategy_name = "complex";
	ps->complexity = "O(n*log n)";
	strategy_complex(ps);
}

static void	go_adaptive_labeled(t_ps *ps, double disorder)
{
	ps->strategy_name = "adaptive";
	if (disorder < 0.2)
	{
		ps->complexity = "O(n^2)";
		strategy_simple(ps);
	}
	else if (disorder < 0.5)
	{
		assign_ranks(ps->a);
		ps->complexity = "O(n*sqrt(n))";
		strategy_medium(ps);
	}
	else
	{
		assign_ranks(ps->a);
		ps->complexity = "O(n*log n)";
		strategy_complex(ps);
	}
}

void	run_strategy(t_ps *ps, double disorder)
{
	if (ps->strat == STRAT_SIMPLE)
		go_simple_labeled(ps);
	else if (ps->strat == STRAT_MEDIUM)
		go_medium_labeled(ps);
	else if (ps->strat == STRAT_COMPLEX)
		go_complex_labeled(ps);
	else
		go_adaptive_labeled(ps, disorder);
}
