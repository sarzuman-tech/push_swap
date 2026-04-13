/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:21:24 by sarzuman          #+#    #+#             */
/*   Updated: 2026/04/13 15:21:26 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *a, const char *b)
{
	int		i;
	size_t	a_len;
	size_t	b_len;

	a_len = ft_strlen(a);
	b_len = ft_strlen(b);
	i = 0;
	if (!a || !b)
		return (0);
	if (a_len > b_len || b_len > a_len)
		return (0);
	while (a[i] != '\0' && b[i] != '\0')
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}
