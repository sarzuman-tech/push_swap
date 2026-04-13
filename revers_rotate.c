/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:00:43 by meharuty          #+#    #+#             */
/*   Updated: 2026/04/13 15:00:46 by meharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revers_rotate(t_list **stake)
{
	t_list	*last;
	t_list	*last_prev;

	if (!stake || !*stake || !(*stake)->next)
		return ;
	last = *stake;
	while (last->next)
		last = last->next;
	last_prev = last->prev;
	(*stake)->prev = last;
	last->next = *stake;
	last->prev = NULL;
	last_prev->next = NULL;
	*stake = last;
}

void	ps_rra(t_ps *ps)
{
	revers_rotate(&ps->a);
	ps_op_emit(ps, OP_RRA, "rra");
}

void	ps_rrb(t_ps *ps)
{
	revers_rotate(&ps->b);
	ps_op_emit(ps, OP_RRB, "rrb");
}

void	ps_rrr(t_ps *ps)
{
	revers_rotate(&ps->a);
	revers_rotate(&ps->b);
	ps_op_emit(ps, OP_RRR, "rrr");
}
