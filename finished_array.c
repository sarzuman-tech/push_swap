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

t_list	*arr_int_to_lst(char *p)
{
	char **arr;
	int *arr_int;
	t_list *a;
	int j = 0;

	arr = ft_split(p, ' ');
	while(arr[j])
		j++;
	arr_int = parse_args(arr, &j);
	a = arr_to_list(arr_int, j);
//	ft_prt_lst(a);
	free(arr_int);
	return (a);
}

t_list	*arr_to_list(int *arr, int size)
{
	t_list *list;
	t_list *node;
	int	i;
	int *num;

	list = NULL;	
	i = 0;
	while (i < size)
	{
		num = malloc(sizeof(int));
		if (!num)
    		return NULL;
		*num = arr[i];
		node = ft_lstnew(num);
		if (!node)
		{
			free(num);
			free_list(list);
			return NULL;
		}
		ft_lstadd_back(&list, node);
		i++;
	}
	return (list);
}

void free_list(t_list *lst)
{
    t_list *tmp;

    while (lst)
    {
        tmp = lst;
        lst = lst->next;
        free(tmp->content);
        free(tmp);
    }
}