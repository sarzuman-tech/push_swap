#include "push_swap.h"

void revers_rotate(t_list **stake)
{
    if (!stake || !*stake || !(*stake)->next)
        return ;
    
    t_list *last;
    t_list *last_prev;
    
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

void rra(t_list **stake_a)
{
    revers_rotate(stake_a);
    ft_printf("rra\n");
}

void rrb(t_list **stake_b)
{
    revers_rotate(stake_b);
    ft_printf("rrb\n");
}

void rrr(t_list **stake_a, t_list **stake_b)
{
    revers_rotate(stake_a);
    revers_rotate(stake_b);
    ft_printf("rrr\n");
}