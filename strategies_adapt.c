/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies_adapt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:24:09 by sarzuman          #+#    #+#             */
/*   Updated: 2026/04/13 15:24:10 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	strategy_adaptive(t_ps *ps, double disorder)
{
	if (disorder < 0.2)
		strategy_simple(ps);
	else if (disorder < 0.5)
		strategy_medium(ps);
	else
		strategy_complex(ps);
}
