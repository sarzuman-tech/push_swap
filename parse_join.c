#include "parse_internal.h"

static char	*parse_join_append(char *arr, const char *piece)
{
	char	*tmp;

	tmp = ft_strjoin(arr, " ");
	free(arr);
	arr = ft_strjoin(tmp, piece);
	free(tmp);
	return (arr);
}

static char	*parse_join_step(char *arr, const char *piece, int *started)
{
	if (!*started)
	{
		*started = 1;
		return (ft_strdup(piece));
	}
	return (parse_join_append(arr, piece));
}

char	*parse_join_argv_numbers(int argc, char **argv)
{
	char	*arr;
	int		i;
	int		started;

	arr = NULL;
	started = 0;
	i = 1;
	while (i < argc)
	{
		if (parse_is_strategy_flag(argv[i]) || parse_is_bench_flag(argv[i]))
		{
			i++;
			continue ;
		}
		arr = parse_join_step(arr, argv[i], &started);
		if (!arr)
			return (NULL);
		i++;
	}
	return (arr);
}
