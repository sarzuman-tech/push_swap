#include "parse_internal.h"

static int	has_dup(long *vals, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (vals[i] == vals[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	validate_token(const char *s)
{
	if (!check_one_arg((char *)s) || !check_overflow((char *)s))
		return (0);
	return (1);
}

static int	fill_read_vals(char **tok, int n, long *vals)
{
	int	vi;

	vi = 0;
	while (vi < n)
	{
		if (!validate_token(tok[vi]))
			return (0);
		vals[vi] = abo(tok[vi]);
		vi++;
	}
	return (1);
}

static void	stack_from_vals(t_list **head, long *vals, int n)
{
	int	i;

	i = n - 1;
	while (i >= 0)
	{
		add_node(head, vals[i]);
		i--;
	}
}

int	parse_fill_stack_from_tokens(char **tok, t_list **head)
{
	int		n;
	long	*vals;

	n = 0;
	while (tok[n])
		n++;
	if (n == 0)
		return (free_all(tok), 0);
	vals = malloc(sizeof(long) * n);
	if (!vals)
		return (free_all(tok), -1);
	if (!fill_read_vals(tok, n, vals))
		return (free(vals), free_all(tok), -1);
	if (has_dup(vals, n))
		return (free(vals), free_all(tok), -1);
	stack_from_vals(head, vals, n);
	free(vals);
	free_all(tok);
	return (1);
}
