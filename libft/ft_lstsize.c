/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:43:53 by sarzuman          #+#    #+#             */
/*   Updated: 2026/02/09 16:44:43 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	size_t	i;

	current = lst;
	if (!lst)
		return (0);
	i = 0;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}
