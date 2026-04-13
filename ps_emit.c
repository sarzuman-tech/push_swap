/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_emit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:23:17 by sarzuman          #+#    #+#             */
/*   Updated: 2026/04/13 15:23:19 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_op_emit(t_ps *ps, t_op op, const char *name)
{
	ps->op_count[op]++;
	ps->total_ops++;
	if (ps->print_ops)
		ft_printf("%s\n", name);
}
