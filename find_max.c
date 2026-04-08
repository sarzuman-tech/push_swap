#include "push_swap.h"

int find_max_position(t_list *b)
{
    t_list *tmp_max;
    t_list *tmp;
    int pos;

    tmp_max = b;
    tmp = b;
    pos = 0;

    while(tmp)
    {
        if(tmp->content > tmp_max->content)
            tmp_max = tmp;
        tmp = tmp->next;
    }
    tmp = b;
    while(tmp)
    {
        if(tmp->content == tmp_max->content)
            break;
        pos++;
        tmp =tmp->next;
    }
    return(pos);
}
int find_max_index(t_list *b)
{
    t_list *tmp_max;
    t_list *tmp;

    tmp_max = b;
    tmp = b;

    while(tmp)
    {
        if(tmp->content > tmp_max->content)
            tmp_max = tmp;
        tmp = tmp->next;
    }
    return (tmp_max->index);
}
