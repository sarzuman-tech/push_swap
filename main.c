#include "push_swap.h"

int main (int argc ,char **argv)
{
    if (argc < 2)
        return 0;
    char    *arr;

    arr = finished_array(argc, argv);
    
    arr_int_to_lst(arr);

    return 0;
}