/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:49:25 by sarzuman          #+#    #+#             */
/*   Updated: 2026/02/03 15:53:19 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	const char	*src;
	char		*arr;
	size_t		i;

	if (!s)
		return (NULL);
	i = 0;
	src = s;
	while (*src != '\0')
	{
		src++;
		i++;
	}
	src = s;
	arr = malloc(sizeof(char) * (i + 1));
	if (!arr)
		return (NULL);
	while (*src)
	{
		*arr = *src;
		arr++;
		src++;
	}
	*arr = '\0';
	return (arr - i);
}
