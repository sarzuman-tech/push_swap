#include "push_swap.h"

void add_node(t_list **head, long content)
{
    t_list *new = malloc(sizeof(t_list));

    new->content = content;
    new->next = *head;
    new->prev = NULL;
    
    if (*head)
        (*head)->prev = new;

    *head = new;
}