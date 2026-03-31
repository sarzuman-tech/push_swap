#include "push_swap.h"

long abo(const char *str)
{
    long result;
    int flag;
    int i;

    result = 0;
    flag = 1;
    i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '-')
    {
        flag = -1;
        i++;
    }
    if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (flag * result);
}

int check_one_arg (char *ptr)
{
    int j;

    j = 0;

    if (ptr[j] == '-' || ptr[j] == '+')
        j++;
    if (!ptr[j])
        return 0;

    while (ptr[j])
    {
        if (!(ptr[j] >= '0' && ptr[j] <= '9'))
            return (0);
        j++;
    }
    
    return (1);
}

int check_overflow(char *ptr)
{
    long res;

    res = abo(ptr);

    if (res > INT_MAX || res < INT_MIN)
        return (0);
    else
        return (1);
}

void free_all(char **ptr)
{
    int m;
    m = 0;

    while (ptr[m])
    {
        free(ptr[m++]);
    }
    free(ptr);
}

void error_checker(char *ptr)
{
    char **arr;
    int i;
    i = 0;

    arr = ft_split(ptr, ' ');

    while (arr[i])
    {
        if (!check_one_arg(arr[i]) || !check_overflow(arr[i]))
        {
            write(2, "Error\n", 6);
            free_all(arr);
            exit(1);
        }
        i++;
    }
    free_all(arr);
}