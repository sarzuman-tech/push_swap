#include "push_swap.h"

void indexing_list(t_list *a)
{
    t_list *current;
    t_list *tmp;

    current = a;

    while(current)
    {
        tmp = a;
        current->index = 0;
        while(tmp)
        {
            if((current->content) > (tmp->content))
                (current->index)++;
            tmp = tmp->next;
        }
        current = current->next;
    }
}