#include "push_swap.h"

static int	rl_init(struct s_rlbuf *x)
{
	x->b = malloc(64);
	if (!x->b)
		return (-1);
	x->c = 64;
	x->l = 0;
	return (0);
}

static int	rl_expand(struct s_rlbuf *x)
{
	char	*nw;
	int		i;

	nw = malloc(x->c * 2);
	if (!nw)
		return (-1);
	i = 0;
	while (i < x->l)
	{
		nw[i] = x->b[i];
		i++;
	}
	free(x->b);
	x->b = nw;
	x->c *= 2;
	return (0);
}

static int	rl_push(struct s_rlbuf *x, char ch)
{
	if (x->l + 1 >= x->c && rl_expand(x))
		return (-1);
	x->b[x->l++] = ch;
	return (0);
}

static int	rl_finish(struct s_rlbuf *x, char **line, int r)
{
	if (r < 0)
		return (free(x->b), -1);
	if (r == 0 && x->l == 0)
		return (free(x->b), 0);
	x->b[x->l] = '\0';
	*line = x->b;
	return (1);
}

int	read_line_stdin(char **line)
{
	struct s_rlbuf	x;
	int				r;
	char			ch;

	if (rl_init(&x))
		return (-1);
	while (1)
	{
		r = read(0, &ch, 1);
		if (r <= 0)
			break ;
		if (ch == '\n')
			break ;
		if (rl_push(&x, ch))
			return (free(x.b), -1);
	}
	return (rl_finish(&x, line, r));
}
