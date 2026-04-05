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
	int j;
	i = argc;
	j = 1;
	
	arr = ft_strdup(argv[j]);
	j++;
	while (j < i)
	{
		tmp = ft_strjoin(arr, " ");
		free(arr);
		arr = ft_strjoin(tmp, argv[j]);
		free(tmp);
		j++;
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
	return (a);
}

t_list	*arr_to_list(int *arr, int size)
{
	t_list *list;
	t_list *node;
	int	i;

	list = NULL;	
	i = 0;
	while (i < size)
	{
		node = ft_lstnew(&arr[i]);
		if (!node)
			return NULL;
		ft_lstadd_back(&list, node);
		i++;
	}
	return (list);
}
