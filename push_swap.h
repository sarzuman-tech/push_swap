#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	long			content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_op;

typedef enum e_strat
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE
}	t_strat;

struct	s_rlbuf
{
	char	*b;
	int		c;
	int		l;
};

typedef struct s_ps
{
	t_list		*a;
	t_list		*b;
	long		op_count[OP_COUNT];
	long		total_ops;
	int			print_ops;
	int			bench;
	t_strat		strat;
	const char	*strategy_name;
	const char	*complexity;
}	t_ps;

char		**ft_split(char const *s, char c);
char		*finished_array(int argc, char **argv);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
long		abo(const char *arr);
void		error_exit(void);
void		free_all(char **ptr);
int			check_overflow(char *ptr);
int			check_one_arg(char *ptr);
void		add_node(t_list **stake, long content);
void		free_stack(t_list **st);
int			ft_lstsize_ps(t_list *lst);

void		sa_logic(t_list **stake_a);
void		sb_logic(t_list **stake_b);
void		ps_sa(t_ps *ps);
void		ps_sb(t_ps *ps);
void		ps_ss(t_ps *ps);
void		ps_pa(t_ps *ps);
void		ps_pb(t_ps *ps);
void		rotate(t_list **stake);
void		ps_ra(t_ps *ps);
void		ps_rb(t_ps *ps);
void		ps_rr(t_ps *ps);
void		revers_rotate(t_list **stake);
void		ps_rra(t_ps *ps);
void		ps_rrb(t_ps *ps);
void		ps_rrr(t_ps *ps);
void		ps_op_emit(t_ps *ps, t_op op, const char *name);

int			ft_printf(const char *format, ...);
int			ft_strcmp(const char *a, const char *b);
size_t		ft_strlen(const char *c);

int			parse_args(int argc, char **argv, t_ps *ps);
int			parse_numbers_to_stack(int argc, char **argv, t_list **head);
double		compute_disorder(t_list *a);
int			is_sorted(t_list *a);
void		assign_ranks(t_list *a);
void		run_strategy(t_ps *ps, double disorder);
void		strategy_simple(t_ps *ps);
void		strategy_medium(t_ps *ps);
void		strategy_complex(t_ps *ps);
void		strategy_adaptive(t_ps *ps, double disorder);
void		print_bench(t_ps *ps, double disorder);

int			apply_instruction(t_ps *ps, const char *line);
int			read_line_stdin(char **line);

#endif
