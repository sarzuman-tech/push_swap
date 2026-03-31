/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:27:56 by sarzuman          #+#    #+#             */
/*   Updated: 2026/02/27 15:39:39 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_printx_x(unsigned int a, char b)
{
	long			count;
	unsigned int	addr;

	count = 0;
	addr = a;
	if (a >= 16)
		count += ft_printx_x(addr / 16, b);
	if (b == 'x')
		count += write(1, &"0123456789abcdef"[addr % 16], 1);
	if (b == 'X')
		count += write(1, &"0123456789ABCDEF"[addr % 16], 1);
	return (count);
}
