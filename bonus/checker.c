#include "../push_swap.h"

static int	chk_load(int argc, char **argv, t_ps *ps)
{
	return (parse_numbers_to_stack(argc, argv, &ps->a));
}

static int	chk_run_ops(t_ps *ps)
{
	char	*ln;
	int		r;

	r = read_line_stdin(&ln);
	while (r > 0)
	{
		if (!apply_instruction(ps, ln))
			return (free(ln), -1);
		free(ln);
		r = read_line_stdin(&ln);
	}
	return (r);
}

static void	chk_finalize(t_ps *ps)
{
	if (is_sorted(ps->a) && ps->b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&ps->a);
	free_stack(&ps->b);
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	int		ret;

	if (argc < 2)
		return (0);
	ps = (t_ps){0};
	ps.print_ops = 0;
	ret = chk_load(argc, argv, &ps);
	if (ret == 0)
		return (0);
	if (ret < 0)
	{
		free_stack(&ps.a);
		error_exit();
	}
	ret = chk_run_ops(&ps);
	if (ret < 0)
	{
		free_stack(&ps.a);
		free_stack(&ps.b);
		error_exit();
	}
	chk_finalize(&ps);
	return (0);
}
