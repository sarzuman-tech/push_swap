#include "push_swap.h"

void	sa_logic(t_list **stake_a)
{
	int		i;
	t_list	*first;
	t_list	*second;
	t_list	*c;

	i = ft_lstsize_ps(*stake_a);
	if (i < 2)
		return ;
	first = *stake_a;
	second = (*stake_a)->next;
	c = second->next;
	second->next = first;
	first->next = c;
	first->prev = second;
	second->prev = NULL;
	if (c)
		c->prev = first;
	*stake_a = second;
}

void	sb_logic(t_list **stake_b)
{
	int		i;
	t_list	*first;
	t_list	*second;
	t_list	*c;

	i = ft_lstsize_ps(*stake_b);
	if (i < 2)
		return ;
	first = *stake_b;
	second = (*stake_b)->next;
	c = second->next;
	second->next = first;
	first->next = c;
	first->prev = second;
	second->prev = NULL;
	if (c)
		c->prev = first;
	*stake_b = second;
}

void	ps_sa(t_ps *ps)
{
	sa_logic(&ps->a);
	ps_op_emit(ps, OP_SA, "sa");
}

void	ps_sb(t_ps *ps)
{
	sb_logic(&ps->b);
	ps_op_emit(ps, OP_SB, "sb");
}

void	ps_ss(t_ps *ps)
{
	sa_logic(&ps->a);
	sb_logic(&ps->b);
	ps_op_emit(ps, OP_SS, "ss");
}
