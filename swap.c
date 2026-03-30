#include "push_swap.h"

void sa_logic (t_list **stake_a)
{
    int i;
    t_list *first;
    t_list *second;
    t_list *c;

    i  = ft_lstsize(*stake_a);
    if (i < 2)
    {
        exit(0);
    }
    first = *stake_a;
    second = (*stake_a)->next;
    c = second->next;

    second->next = first;
    first->next = c;
    first->prev = second;
    second->prev = NULL;

    *stake_a = second;
}

void sb_logic (t_list **stake_b)
{
    int i;
    t_list *first;
    t_list *second;
    t_list *c;
    
    i  = ft_lstsize(*stake_b);
    if (i < 2)
    {
        exit(0);
    }
    
    first = *stake_b;
    second = (*stake_b)->next;
    c = second->next;

    second->next = first;
    first->next = c;
    first->prev = second;
    second->prev = NULL;

    *stake_b = second;
}

void ss(t_list **stake_a, t_list **stake_b)
{
    sa_logic(stake_a);
    sb_logic(stake_b);

    ft_printf("%s\n", "ss");
}

void sa(t_list **stake_a)
{
    sa_logic(stake_a);
    ft_printf("%s\n", "sa");
}

void sb(t_list **stake_b)
{
    sb_logic(stake_b);
    ft_printf("%s\n", "sb");
}