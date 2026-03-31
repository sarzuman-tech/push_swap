/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:42:28 by sarzuman          #+#    #+#             */
/*   Updated: 2026/01/31 14:02:43 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	cr;

	src = (unsigned char *)s;
	cr = (unsigned char)c;
	while (n--)
	{
		*src = cr;
		src++;
	}
	return (s);
}
