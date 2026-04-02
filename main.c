#include "push_swap.h"

int main (int argc, char **argv)
{
    t_list *stake_a = NULL;
    // t_list *stake_b = NULL;
    char *arr;
    char **arr_split;
    int i;

    arr = finished_array(argc, argv);

    arr_split = ft_split(arr, ' ');

    i = 0;
    while (arr_split[i])
    {
        add_node(&stake_a, abo(arr_split[i]));
        i++;
    }

    buble_sort(&stake_a);
    
    

    
    



    

    return 0;
}