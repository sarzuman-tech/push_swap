/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:33:03 by sarzuman          #+#    #+#             */
/*   Updated: 2026/02/27 15:36:26 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

long	ft_printx_x(unsigned int a, char b);
long	ft_print_unsigned(unsigned int a);
long	ft_print_adr(void *a);
long	ft_printstr(char *a);
long	ft_helper(char a, va_list *args);
long	ft_printnbr(int a);
long	ft_printchr(int a);

int		ft_puthex_base(unsigned long addr, char *base);

#endif
