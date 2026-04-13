/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:22:19 by sarzuman          #+#    #+#             */
/*   Updated: 2026/04/13 15:22:20 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_internal.h"

int	parse_is_strategy_flag(const char *s)
{
	return (ft_strcmp(s, "--simple") == 1 || ft_strcmp(s, "--medium") == 1
		|| ft_strcmp(s, "--complex") == 1 || ft_strcmp(s, "--adaptive") == 1);
}

int	parse_is_bench_flag(const char *s)
{
	return (ft_strcmp(s, "--bench") == 1);
}

void	parse_set_strat(t_ps *ps, const char *s)
{
	if (ft_strcmp(s, "--simple") == 1)
		ps->strat = STRAT_SIMPLE;
	else if (ft_strcmp(s, "--medium") == 1)
		ps->strat = STRAT_MEDIUM;
	else if (ft_strcmp(s, "--complex") == 1)
		ps->strat = STRAT_COMPLEX;
	else
		ps->strat = STRAT_ADAPTIVE;
}

int	parse_count_non_flag_args(int argc, char **argv)
{
	int	i;
	int	n;

	n = 0;
	i = 1;
	while (i < argc)
	{
		if (!parse_is_strategy_flag(argv[i]) && !parse_is_bench_flag(argv[i]))
			n++;
		i++;
	}
	return (n);
}
