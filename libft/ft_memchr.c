/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:51:22 by sarzuman          #+#    #+#             */
/*   Updated: 2026/02/01 16:16:58 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		dst;

	src = (const unsigned char *)s;
	dst = (unsigned char)c;
	while (n > 0)
	{
		if (*src == dst)
		{
			return ((void *)src);
		}
		src++;
		n--;
	}
	return (NULL);
}
