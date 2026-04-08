#include "parse_internal.h"

static void	apply_cli_flags(int argc, char **argv, t_ps *ps)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (parse_is_strategy_flag(argv[i]))
			parse_set_strat(ps, argv[i]);
		else if (parse_is_bench_flag(argv[i]))
			ps->bench = 1;
		i++;
	}
}

int	parse_args(int argc, char **argv, t_ps *ps)
{
	char	*joined;
	char	**tok;
	int		nn;

	ps->strat = STRAT_ADAPTIVE;
	ps->bench = 0;
	apply_cli_flags(argc, argv, ps);
	nn = parse_count_non_flag_args(argc, argv);
	if (nn == 0)
		return (0);
	joined = parse_join_argv_numbers(argc, argv);
	if (!joined)
		return (-1);
	tok = ft_split(joined, ' ');
	free(joined);
	if (!tok)
		return (-1);
	return (parse_fill_stack_from_tokens(tok, &ps->a));
}

int	parse_numbers_to_stack(int argc, char **argv, t_list **head)
{
	char	*joined;
	char	**tok;

	if (argc < 2)
		return (0);
	joined = finished_array(argc, argv);
	if (!joined)
		return (-1);
	tok = ft_split(joined, ' ');
	free(joined);
	if (!tok)
		return (-1);
	return (parse_fill_stack_from_tokens(tok, head));
}
