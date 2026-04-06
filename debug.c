#include "push_swap.h"

void debug_list(t_list *lst)
{
    t_list *tmp = lst;

    printf("LIST\n");

    while (tmp)
    {
        printf("%d ", *(int *)tmp->content);
        tmp = tmp->next;
    }
}

void debug_config(t_config *cfg)
{
    printf("CONFIG\n");

    if (cfg->strategy)
        printf("%s\n", cfg->strategy);
    else
        printf("NULL\n");

    printf("%d\n", cfg->bench);
    printf("count = %d\n", cfg->config_count);
}