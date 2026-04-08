#include "push_swap.h"

void	add_node(t_list **head, long content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->content = content;
	new->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;
	*head = new;
}

int	ft_lstsize_ps(t_list *lst)
{
	int		i;
	t_list	*c;

	i = 0;
	c = lst;
	while (c)
	{
		i++;
		c = c->next;
	}
	return (i);
}

void	free_stack(t_list **st)
{
	t_list	*n;
	t_list	*c;

	if (!st || !*st)
		return ;
	c = *st;
	while (c)
	{
		n = c->next;
		free(c);
		c = n;
	}
	*st = NULL;
}
