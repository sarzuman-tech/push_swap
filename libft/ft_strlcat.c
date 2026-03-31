/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:46:12 by sarzuman          #+#    #+#             */
/*   Updated: 2026/01/31 18:18:04 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	slen = 0;
	while (src[slen] != '\0')
		slen++;
	dlen = 0;
	while (dlen < dstsize && dst[dlen] != '\0')
		dlen++;
	if (dlen == dstsize)
		return (dstsize + slen);
	i = 0;
	while (src[i] != '\0' && (dlen + i + 1) < dstsize)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
