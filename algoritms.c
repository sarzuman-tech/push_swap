#include "push_swap.h"

void buble_sort(t_list **stake)
{
    t_list *current;
    t_list *last = NULL;

    current = *stake;
    int sorted = 1;

    while (current->next != last)
    {
        if (current->content > current->next->content)
        {
            sa(stake);
            current = *stake;
        }

        

    }

}