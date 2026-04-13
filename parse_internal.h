/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:22:32 by sarzuman          #+#    #+#             */
/*   Updated: 2026/04/13 15:22:39 by sarzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INTERNAL_H
# define PARSE_INTERNAL_H

# include "push_swap.h"

int		parse_is_strategy_flag(const char *s);
int		parse_is_bench_flag(const char *s);
void	parse_set_strat(t_ps *ps, const char *s);
int		parse_count_non_flag_args(int argc, char **argv);
char	*parse_join_argv_numbers(int argc, char **argv);
int		parse_fill_stack_from_tokens(char **tok, t_list **head);

#endif
