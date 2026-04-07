#include "push_swap.h"

int main(int argc, char **argv)
{
    t_config *cfg;
    t_list *list;

    cfg = ft_config_init(argv + 1);
    debug_config(cfg);

   char *str = finished_array(argc, argv);
    list = arr_int_to_lst(str);
    free(str);
    debug_list(list);

    return 0;
}