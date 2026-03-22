#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <unistd.h>

char	**ft_split(char const *s, char c);
char *finished_array(int argc, char **argv);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int	ft_atoi(const char *str);
long abo(const char *arr);
void error_checker(char *ptr);
void free_all(char **ptr);
int check_overflow(char *ptr);
int check_one_arg (char *ptr);


#endif