/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharuty <meharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:41:20 by sarzuman          #+#    #+#             */
/*   Updated: 2026/03/31 18:05:47 by meharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_helper(char a, va_list *args)
{
	long	count;

	count = 0;
	if (a == 'd' || a == 'i')
		count += ft_printnbr(va_arg(*args, int));
	if (a == 'c')
		count += ft_printchr(va_arg(*args, int));
	if (a == 's')
		count += ft_printstr(va_arg(*args, char *));
	if (a == 'p')
		count += ft_print_adr(va_arg(*args, void *));
	if (a == 'u')
		count += ft_print_unsigned(va_arg(*args, unsigned int));
	if (a == 'x' || a == 'X')
		count += ft_printx_x(va_arg(*args, unsigned int), a);
	if (a == '%')
	{
		write (1, "%", 1);
		count++;
	}
	if (a == 'm')
		ft_print_double(va_arg(*args, double));
	return (count);
}
