/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 12:52:54 by sarzuman          #+#    #+#             */
/*   Updated: 2026/02/01 13:15:00 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*out;

	out = (char *)s;
	while (*out != '\0')
	{
		if (*out == (char)c)
			return (out);
		out++;
	}
	if ((char)c == '\0')
		return (out);
	return (NULL);
}
