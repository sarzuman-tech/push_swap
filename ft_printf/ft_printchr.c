/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:31:19 by sarzuman          #+#    #+#             */
/*   Updated: 2026/02/27 15:31:49 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_printchr(int a)
{
	long	count;

	count = 0;
	if (!a)
		return (count);
	write (1, &a, 1);
	count++;
	return (count);
}
