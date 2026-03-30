#include "push_swap.h"

int main ()
{
    char *arr[] = {"16", "15", "--simple" ,"18", "--bench"};
    t_config *data;

    data = ft_config_init(arr);
    
    ft_printf("%s\n %d", data->strategy, data->config_count);

    return 0;
}