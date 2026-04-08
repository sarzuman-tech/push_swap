#include "push_swap.h"

static int	ap_try_swap(t_ps *ps, const char *ln)
{
	if (ft_strcmp(ln, "sa") == 1)
	{
		ps_sa(ps);
		return (1);
	}
	if (ft_strcmp(ln, "sb") == 1)
	{
		ps_sb(ps);
		return (1);
	}
	if (ft_strcmp(ln, "ss") == 1)
	{
		ps_ss(ps);
		return (1);
	}
	return (0);
}

static int	ap_try_push(t_ps *ps, const char *ln)
{
	if (ft_strcmp(ln, "pa") == 1)
	{
		ps_pa(ps);
		return (1);
	}
	if (ft_strcmp(ln, "pb") == 1)
	{
		ps_pb(ps);
		return (1);
	}
	return (0);
}

static int	ap_try_rot(t_ps *ps, const char *ln)
{
	if (ft_strcmp(ln, "ra") == 1)
	{
		ps_ra(ps);
		return (1);
	}
	if (ft_strcmp(ln, "rb") == 1)
	{
		ps_rb(ps);
		return (1);
	}
	if (ft_strcmp(ln, "rr") == 1)
	{
		ps_rr(ps);
		return (1);
	}
	return (0);
}

static int	ap_try_rev(t_ps *ps, const char *ln)
{
	if (ft_strcmp(ln, "rra") == 1)
	{
		ps_rra(ps);
		return (1);
	}
	if (ft_strcmp(ln, "rrb") == 1)
	{
		ps_rrb(ps);
		return (1);
	}
	if (ft_strcmp(ln, "rrr") == 1)
	{
		ps_rrr(ps);
		return (1);
	}
	return (0);
}

int	apply_instruction(t_ps *ps, const char *line)
{
	if (ap_try_swap(ps, line))
		return (1);
	if (ap_try_push(ps, line))
		return (1);
	if (ap_try_rot(ps, line))
		return (1);
	if (ap_try_rev(ps, line))
		return (1);
	return (0);
}
