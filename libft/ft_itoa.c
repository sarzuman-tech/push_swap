/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 21:03:49 by sarzuman          #+#    #+#             */
/*   Updated: 2026/02/05 21:30:32 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	n_l;
	int		len;
	char	*str;

	n_l = n;
	len = get_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n_l == 0)
		str[0] = '0';
	if (n_l < 0)
	{
		str[0] = '-';
		n_l = -n_l;
	}
	while (n_l > 0)
	{
		str[--len] = (n_l % 10) + '0';
		n_l /= 10;
	}
	return (str);
}
