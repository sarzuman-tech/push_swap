/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:04:57 by meharuty          #+#    #+#             */
/*   Updated: 2026/04/13 15:04:59 by meharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(char **ptr)
{
	int	m;

	m = 0;
	while (ptr[m])
		free(ptr[m++]);
	free(ptr);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	error_checker(char *ptr)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_split(ptr, ' ');
	while (arr[i])
	{
		if (!check_one_arg(arr[i]) || !check_overflow(arr[i]))
		{
			write(2, "Error\n", 6);
			free_all(arr);
			exit(1);
		}
		i++;
	}
	free_all(arr);
}
