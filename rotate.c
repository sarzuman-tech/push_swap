#include "push_swap.h"

void rotate(t_list **stake)
{
    t_list *last;
    t_list *second;

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

void ra(t_list **stake_a)
{
    rotate(stake_a);
    ft_printf("ra\n");
}

void rb(t_list **stake_b)
{
    rotate(stake_b);
    ft_printf("rb\n");
}

void rr(t_list **stake_a, t_list **stake_b)
{
    rotate(stake_a);
    rotate(stake_b);
    ft_printf("rr\n");
}