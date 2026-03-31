/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:44:18 by sarzuman          #+#    #+#             */
/*   Updated: 2026/02/09 18:54:00 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*t1;
	const unsigned char	*t2;

	t1 = (const unsigned char *)s1;
	t2 = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*t1 != *t2)
		{
			return (*t1 - *t2);
		}
		t1++;
		t2++;
		n--;
	}
	return (0);
}
