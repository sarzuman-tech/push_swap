#include "push_swap.h"

int main(int argc, char **argv)
{
    t_config *cfg;
    t_list *list;

    cfg = ft_config_init(argv + 1);
    debug_config(cfg);

    list = parse_input(argc, argv);
    debug_list(list);

    return 0;
}