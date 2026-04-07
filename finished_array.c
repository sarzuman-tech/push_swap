#include "push_swap.h"

//static void ft_prt_lst(t_list *lst)
//{
//	t_list *tmp;
//	tmp = lst;
//
//	while (tmp)
//	{
//		printf("%d ", *(int*)tmp->content);
//		tmp = tmp->next;
//	}
//}

char *finished_array(int argc, char **argv)
{
	char *arr;
	char *tmp;
	int i;

	arr = NULL;
	i = 1;
	
	while (i < argc)
	{
    	if (is_flag(argv[i]))
    	{
        	i++;
        	continue;
    	}
    	if (!arr)
        	arr = ft_strdup(argv[i]);
    	else
    	{
        	tmp = ft_strjoin(arr, " ");
        	free(arr);
        	arr = ft_strjoin(tmp, argv[i]);
        	free(tmp);
    	}
    	i++;
    }
    return (arr);
}

t_list *arr_int_to_lst(char *p)
{
    char **arr;
    t_list *list;
    int i;

    arr = ft_split(p, ' ');
    if (!arr)
        return NULL;

    list = NULL;
    i = 0;

    while (arr[i])
    {
		long value;

        if (!check_one_arg(arr[i]) || !abo(arr[i], &value))
		{
			write(2, "Error\n", 6);
    		free_all(arr);
    		free_list(list);
    		exit (1);
		}
		if (check_duplicate(list, (int)value))
        {
            write(2, "Error\n", 6);
            free_all(arr);
            free_list(list);
            exit (1);
        }
        t_list *node = ft_lstnew((int)value);
        if (!node)
            return (free_all(arr), free_list(list), NULL);

        ft_lstadd_back(&list, node);
        i++;
    }

    free_all(arr);
    return list;
}

void free_list(t_list *lst)
{
    t_list *tmp;

    while (lst)
    {
        tmp = lst;
        lst = lst->next;
        free(tmp);
    }
}