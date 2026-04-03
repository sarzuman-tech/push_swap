#include "push_swap.h"

void simple_sort(t_list **stake_a)
{
    t_list *stake_b;
    int size;
    int small;

    stake_b = NULL;
    size = stack_size(stake_a);
    small = 0;

    while (*stake_a)
    {
        small = find_min_position(*stake_a);
        if (small <= size / 2)
            while(small-- > 0)
                ra(stake_a);
        else
            while(small++ < size)
                rra(stake_a);
        pb(stake_a, &stake_b);
        size--;
    }
    while (stake_b)
        pa(&stake_b, stake_a);
}
