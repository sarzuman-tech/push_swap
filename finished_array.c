#include "push_swap.h"

char *finished_array(int argc, char **argv)
{
    char *arr;
    char *tmp;
    int i;
    int j;
    i = argc;
    j = 1;
    
    arr = ft_strdup(argv[j]);
    j++;
    while (j < i)
    {
        tmp = ft_strjoin(arr, " ");
        free(arr);
        arr = ft_strjoin(tmp, argv[j]);
        free(tmp);
        j++;
    }
    return (arr);
}