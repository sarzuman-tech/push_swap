/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:20:58 by sarzuman          #+#    #+#             */
/*   Updated: 2026/04/13 15:21:01 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	abo(const char *str)
{
	long	result;
	int		flag;
	int		i;

	result = 0;
	flag = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
	{
		flag = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (flag * result);
}

int	check_one_arg(char *ptr)
{
	int	j;

	j = 0;
	if (ptr[j] == '-' || ptr[j] == '+')
		j++;
	if (!ptr[j])
		return (0);
	while (ptr[j])
	{
		if (!(ptr[j] >= '0' && ptr[j] <= '9'))
			return (0);
		j++;
	}
	return (1);
}

int	check_overflow(char *ptr)
{
	long	res;

	res = abo(ptr);
	if (res > INT_MAX || res < INT_MIN)
		return (0);
	return (1);
}
