#include "push_swap.h"

void	strategy_adaptive(t_ps *ps, double disorder)
{
	if (disorder < 0.2)
		strategy_simple(ps);
	else if (disorder < 0.5)
		strategy_medium(ps);
	else
		strategy_complex(ps);
}
