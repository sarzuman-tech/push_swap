#include "push_swap.h"

int stack_size(t_list **stack)
{
    t_list *arr;
    int size;

    arr = *stack;
    size = 0;

    while (arr)
    {
        arr = arr->next;
        size++;
    }
    return (size);
}

int find_min_position(t_list *stack)
{
    if (!stack)
        return (0);
    t_list *arr;
    int min_value;
    int min_pos;
    int current_pos;

    arr = stack;
    min_value = arr->content;
    min_pos = 0;
    current_pos = 0;

    arr = arr->next;

    while (arr)
    {
        current_pos++;
        if(arr->content < min_value)
        {
            min_value = arr->content;
            min_pos = current_pos;
        }
        arr = arr->next;
    }
    return (min_pos);
}