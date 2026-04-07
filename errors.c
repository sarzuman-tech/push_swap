#include "push_swap.h"

int abo(const char *str, long *res)
{
    long result;
    int flag;
    int i;

    result = 0;
    flag = 1;
    i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            flag = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        if ((flag == 1 && result > INT_MAX) || (flag == -1 && -result < INT_MIN))
			return (0);
        i++;
    }
    (*res) = result * flag;
    return (1);
}

int check_one_arg (char *ptr)
{
    int j;

    j = 0;

    if (ptr[j] == '-' || ptr[j] == '+')
        j++;
    if (!ptr[j])
        return (0);

    while (ptr[j])
    {
        if (!(ptr[j] >= '0' && ptr[j] <= '9'))
            return (0);
        j++;
    }
    return (1);
}

int check_duplicate(t_list *list, int value)
{
    while (list)
    {
        if (list->content == value)
            return 1;
        list = list->next;
    }
    return 0;
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