NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c parse_flags.c parse_join.c parse_load.c parse_cli.c ps_emit.c disorder.c bench.c \
	finished_array.c errors_num.c errors_exit.c \
	list_manipulations.c swap.c push.c rotate.c revers_rotate.c ft_strcmp.c \
	strategies_rank.c strategies_simple.c strategies_medium.c strategies_complex.c \
	strategies_adapt.c strategies_run.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ft_printf
PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -lm -o $(NAME)

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

parse_flags.o: parse_flags.c parse_internal.h push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

parse_join.o: parse_join.c parse_internal.h push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

parse_load.o: parse_load.c parse_internal.h push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

parse_cli.o: parse_cli.c parse_internal.h push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all bonus clean fclean re
