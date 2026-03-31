/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:27:28 by sarzuman          #+#    #+#             */
/*   Updated: 2026/01/31 16:41:36 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*s;
	char		*d;
	size_t		i;
	const char	*temp;

	s = src;
	d = dst;
	i = 0;
	temp = s;
	while (*temp != '\0')
	{
		i++;
		temp++;
	}
	if (dstsize == 0)
		return (i);
	while (dstsize > 1 && *s != '\0')
	{
		*d = *s;
		d++;
		s++;
		dstsize--;
	}
	*d = '\0';
	return (i);
}
