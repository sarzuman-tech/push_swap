#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <unistd.h>

typedef struct s_list {
	
	int content;
	int index;
	struct s_list *next;
	struct s_list *prev;
} t_list;

typedef struct s_config{
	int config_count;
	char *strategy;
	int bench;
} t_config;

char	**ft_split(char const *s, char c);
char    *finished_array(int argc, char **argv);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
int		abo(const char *arr, long *res);
void	error_checker(char *ptr);
void	free_all(char **ptr);
int		check_overflow(char *ptr);
int		check_one_arg (char *ptr);
void add_node(t_list **stake, long content);
t_list *make_list(t_list **stake);
//------Swap------//
void sa (t_list **stake_a);
void sb (t_list **stake_b);
void sa_logic (t_list **stake_a);
void sb_logic (t_list **stake_b);
void ss(t_list **stake_a, t_list **stake_b);
//------Push------//
void pb(t_list **stake_a, t_list **stake_b);
void pa(t_list **stake_b, t_list **stake_a);
//------Rotate------//
void rotate(t_list **stake);
void ra(t_list **stake_a);
void rb(t_list **stake_b);
void rr(t_list **stake_a, t_list **stake_b);

//------ReversRotate------//
void revers_rotate(t_list **stake);
void rra(t_list **stake_a);
void rrb(t_list **stake_b);
void rrr(t_list **stake_a, t_list **stake_b);

int	ft_printf(const char *format, ...);
int	ft_lstsize(t_list *lst);
int is_flag(char *arg);
t_list *arr_int_to_lst(char *p);
void free_list(t_list *lst);

int check_duplicate(t_list *list, int value);
t_list *ft_lstnew(int content);
void ft_lstadd_back(t_list **lst, t_list *new);
int	ft_strcmp(const char *a, const char *b);
const char *ft_strategy_search(char **arr);
int ft_bench_search(char **arr);
t_config *ft_config_init(char **arr);
size_t	ft_strlen(const char *c);
void debug_config(t_config *cfg);
void debug_list(t_list *lst);
void indexing_list(t_list *a);
int find_max_position(t_list *b);
int find_max_index(t_list *b);
void chunk_sort(t_list **a);
#endif