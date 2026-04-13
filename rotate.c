/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:00:56 by meharuty          #+#    #+#             */
/*   Updated: 2026/04/13 15:00:58 by meharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stake)
{
	t_list	*last;
	t_list	*second;

	last = *stake;
	if (!last || !last->next)
		return ;
	second = (*stake)->next;
	while (last->next)
		last = last->next;
	last->next = *stake;
	(*stake)->next = NULL;
	(*stake)->prev = last;
	second->prev = NULL;
	*stake = second;
}

void	ps_ra(t_ps *ps)
{
	rotate(&ps->a);
	ps_op_emit(ps, OP_RA, "ra");
}

void	ps_rb(t_ps *ps)
{
	rotate(&ps->b);
	ps_op_emit(ps, OP_RB, "rb");
}

void	ps_rr(t_ps *ps)
{
	rotate(&ps->a);
	rotate(&ps->b);
	ps_op_emit(ps, OP_RR, "rr");
}
