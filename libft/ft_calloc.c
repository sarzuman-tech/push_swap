/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:41:23 by sarzuman          #+#    #+#             */
/*   Updated: 2026/02/04 14:48:29 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*arr;
	size_t			sum;
	unsigned char	*p;

	if (count == 0 || size == 0)
		return (malloc(1));
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	sum = count * size;
	arr = malloc(sum);
	if (!arr)
		return (NULL);
	p = (unsigned char *)arr;
	while (sum > 0)
	{
		*p = '\0';
		p++;
		sum--;
	}
	return (arr);
}
