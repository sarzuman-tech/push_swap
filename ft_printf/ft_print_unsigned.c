/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:30:12 by sarzuman          #+#    #+#             */
/*   Updated: 2026/02/27 15:30:54 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_print_unsigned(unsigned int a)
{
	long	count;

	count = 0;
	if (a >= 10)
		count += ft_print_unsigned(a / 10);
	count += write(1, &"0123456789"[a % 10], 1);
	return (count);
}
