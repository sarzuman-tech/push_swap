/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:33:00 by sarzuman          #+#    #+#             */
/*   Updated: 2026/02/01 13:54:30 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*out;

	out = (char *)s;
	while (*out != '\0')
	{
		out++;
	}
	while (out >= s)
	{
		if (*out == (char)c)
		{
			return (out);
		}
		out--;
	}
	return (NULL);
}
