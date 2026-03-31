/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:42:16 by sarzuman          #+#    #+#             */
/*   Updated: 2026/02/23 21:00:21 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_printnbr(int a)
{
	char	*res;
	long	count;
	long	i;

	i = 0;
	count = 0;
	res = ft_itoa(a);
	count += ft_strlen(res);
	while (res[i] != '\0')
	{
		write (1, &res[i], 1);
		i++;
	}
	free(res);
	return (count);
}
