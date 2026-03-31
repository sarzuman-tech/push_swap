/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:26:01 by sarzuman          #+#    #+#             */
/*   Updated: 2026/02/05 20:31:39 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	**freeall(char **arr, size_t j)
{
	while (j > 0)
	{
		j--;
		free(arr[j]);
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	start;

	if (!s)
		return (NULL);
	arr = ft_calloc(count_word(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_word(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		arr[j] = ft_substr(s, start, i - start);
		if (!arr[j])
			return (freeall(arr, j));
		j++;
	}
	return (arr);
}
