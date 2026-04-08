#include "push_swap.h"

void	ps_op_emit(t_ps *ps, t_op op, const char *name)
{
	ps->op_count[op]++;
	ps->total_ops++;
	if (ps->print_ops)
		ft_printf("%s\n", name);
}
