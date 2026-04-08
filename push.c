#include "push_swap.h"

static void	pb_logic(t_list **stake_a, t_list **stake_b)
{
	t_list	*tmp;

	if (!stake_a || !*stake_a)
		return ;
	tmp = *stake_a;
	*stake_a = (*stake_a)->next;
	if (*stake_a)
		(*stake_a)->prev = NULL;
	tmp->next = *stake_b;
	tmp->prev = NULL;
	if (*stake_b)
		(*stake_b)->prev = tmp;
	*stake_b = tmp;
}

static void	pa_logic(t_list **stake_b, t_list **stake_a)
{
	t_list	*tmp;

	if (!stake_b || !*stake_b)
		return ;
	tmp = *stake_b;
	*stake_b = (*stake_b)->next;
	if (*stake_b)
		(*stake_b)->prev = NULL;
	tmp->next = *stake_a;
	tmp->prev = NULL;
	if (*stake_a)
		(*stake_a)->prev = tmp;
	*stake_a = tmp;
}

void	ps_pb(t_ps *ps)
{
	if (!ps->a)
		return ;
	pb_logic(&ps->a, &ps->b);
	ps_op_emit(ps, OP_PB, "pb");
}

void	ps_pa(t_ps *ps)
{
	if (!ps->b)
		return ;
	pa_logic(&ps->b, &ps->a);
	ps_op_emit(ps, OP_PA, "pa");
}
