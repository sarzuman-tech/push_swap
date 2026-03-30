#include "push_swap.h"

void pb(t_list **stake_a, t_list **stake_b)
{
    if (!stake_a || !*stake_a)
        return ;

    t_list *tmp;

    tmp = *stake_a;
    *stake_a = (*stake_a)->next;
    if (*stake_a)
        (*stake_a)->prev = NULL;

    tmp->next = *stake_b;
    tmp->prev = NULL;

    if (*stake_b)
        (*stake_b)->prev = tmp;

    *stake_b = tmp;
    ft_printf("%s\n", "pb");
}

void pa(t_list **stake_b, t_list **stake_a)
{
    if (!stake_b || !*stake_b)
        return ;

    t_list *tmp;

    tmp = *stake_b;
    *stake_b = (*stake_b)->next;
    if (*stake_b)
        (*stake_b)->prev = NULL;

    tmp->next = *stake_a;
    tmp->prev = NULL;

    if (*stake_a)
        (*stake_a)->prev = tmp;

    *stake_a = tmp;
    ft_printf("%s\n", "pa");
}