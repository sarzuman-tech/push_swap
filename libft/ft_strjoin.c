/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:51:48 by sarzuman          #+#    #+#             */
/*   Updated: 2026/02/04 16:15:20 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	arr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		arr[i] = s2[j];
		i++;
		j++;
	}
	arr[i] = '\0';
	return (arr);
}
