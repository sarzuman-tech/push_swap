/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:26:37 by sarzuman          #+#    #+#             */
/*   Updated: 2026/02/27 15:27:22 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_base(unsigned long addr, char *base)
{
	int	count;

	count = 0;
	if (addr >= 16)
		count += ft_puthex_base(addr / 16, base);
	count += write(1, &base[addr % 16], 1);
	return (count);
}

long	ft_print_adr(void *a)
{
	long			count;
	unsigned long	addr;

	count = 0;
	if (a == NULL)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	addr = (unsigned long)a;
	count += write(1, "0x", 2);
	count += ft_puthex_base(addr, "0123456789abcdef");
	return (count);
}
