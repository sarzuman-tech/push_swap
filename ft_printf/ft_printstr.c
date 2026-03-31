/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:36:57 by sarzuman          #+#    #+#             */
/*   Updated: 2026/02/27 15:37:04 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_printstr(char *a)
{
	long	count;

	count = 0;
	if (!a)
		a = "(null)";
	while (*a != '\0')
	{
		write (1, a, 1);
		a++;
		count++;
	}
	a = NULL;
	return (count);
}
