#include "push_swap.h"

int main (int argc ,char **argv)
{
    if (argc < 2)
        return 0;
    char *arr;
    char **ptr;
    int i = 0;
    int m = 0;

    arr = finished_array(argc, argv);

    error_checker(arr);
    
    ptr = ft_split(arr, ' ');

    while (ptr[i])
    {
        printf("%s ", ptr[i]);
        i++;
    }
    
    while (ptr[m])
    {
        free(ptr[m++]);
    }
    free(arr);
    free(ptr);

    return 0;
}