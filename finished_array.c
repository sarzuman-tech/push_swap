/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finished_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:07:37 by meharuty          #+#    #+#             */
/*   Updated: 2026/04/13 15:07:40 by meharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*finished_array(int argc, char **argv)
{
	char	*arr;
	char	*tmp;
	int		i;
	int		j;

	i = argc;
	j = 1;
	arr = ft_strdup(argv[j]);
	j++;
	while (j < i)
	{
		tmp = ft_strjoin(arr, " ");
		free(arr);
		arr = ft_strjoin(tmp, argv[j]);
		free(tmp);
		j++;
	}
	return (arr);
}
