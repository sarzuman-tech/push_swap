/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:05:30 by sarzuman          #+#    #+#             */
/*   Updated: 2026/02/06 12:35:31 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*src;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	src = malloc(sizeof(char) * (len + 1));
	if (!src)
		return (NULL);
	i = 0;
	while (i < len)
	{
		src[i] = f(i, s[i]);
		i++;
	}
	src[i] = '\0';
	return (src);
}
