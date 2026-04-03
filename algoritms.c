#include "push_swap.h"

void buble_sort(t_list **stake)
{
    int swapped;
    t_list *current;
    t_list *boundary;

    if (!stake || !*stake || !(*stake)->next)
        return;

    boundary = NULL;
    swapped = 1;

    while (swapped)
    {
        swapped = 0;
        current = *stake;

        while (current->next != boundary)
        {
            if (current->content > current->next->content)
            {
                sa(stake);
                swapped = 1;
                // после sa нужно начать с начала
                current = *stake;
                continue;
            }
            current = current->next;
        }
        boundary = current;
    }
}