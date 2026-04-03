#include "push_swap.h"

int is_sort(t_list **stake_a)
{
    t_list *arr;
    arr = *stake_a;

    while (arr->next)
    {
        if (arr->content > arr->next->content)
            return 0;
        arr = arr->next;
    }
    return 1;
}