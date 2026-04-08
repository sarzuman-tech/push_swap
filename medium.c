#include "push_swap.h"

static int chunk_count(t_list *a)
{
	int size;

	size = ft_lstsize(a);
	if (size <= 100)
		return (5);
	else
		return (11);
}
void chunk_sort(t_list **a)
{
	t_list *b;
	int count_chunk;
	int size;
	int i;
	int start;
	int end;
	int chunk_size;
	int pushed;
	int value;
	int pos;

	i = 0;
	b = NULL;
	size = ft_lstsize(*a);
	count_chunk = chunk_count(*a);
	chunk_size = (size + count_chunk - 1) / count_chunk;

	while(i < count_chunk)
	{
		start = i * chunk_size;
		end = start + chunk_size -1;
		pushed = 0;
		while(pushed < (end - start + 1) && (*a))
		{
			value = (*a)->index;
			if(value >= start && value <= end)
			{
				pb(a, &b);
				if((b)->index <= (start + end)/2)
					rb(&b);
				pushed++;
			}
			else
				ra(a);
		}
		i++;
	}
	while(b)
	{
		pos = find_max_position(b);
		if(pos <= size / 2)
		{
			while((b->index) != find_max_index(b))
				rb(&b);
		}
		else
		{
			while((b->index) != find_max_index(b))
				rrb(&b);
		}
		pa(&b, a);
	}
}
