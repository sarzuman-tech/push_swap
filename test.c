#include "push_swap.h"

int is_flag(char *arg)
{
    if (!ft_strcmp(arg, "--simple")
        || !ft_strcmp(arg, "--medium")
        || !ft_strcmp(arg, "--complex")
        || !ft_strcmp(arg, "--bench"))
        return (1);
    return (0);
}

const char *ft_strategy_search(char **arr)
{
    int i;
    int j;
    i = 0;
    j = 2;
    if (!arr)
        return NULL;

    while (i < j)
    {
            if (ft_strcmp(arr[i], "--simple"))
                return ("simple");
            if (ft_strcmp(arr[i], "--medium"))
                return ("medium");
            if (ft_strcmp(arr[i], "--complex"))
                return ("complex");
        i++;
    }
    return(NULL);
}

int ft_bench_search(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        if (ft_strcmp(arr[i], "--bench"))
            return (1);
        i++;
    }
    return 0;
}

t_config *ft_config_init(char **arr)
{
    t_config *config_data;
    int config_count;
    
    config_count = 0;
    config_data = malloc((sizeof(t_config)));
    if (!config_data)
        return NULL;

    config_data->strategy = (char *)ft_strategy_search(arr);
    config_data->bench = ft_bench_search(arr);

    if  (config_data->strategy != NULL)
        config_count++;
    if  (config_data->bench != 0)
        config_count++;
    if (config_data->strategy == NULL)
    {
        config_data->strategy = "adaptive";
    }
    config_data->config_count = config_count;
    return (config_data);
}