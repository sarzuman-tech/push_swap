NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
LIBFT_PATH_LIB = ../libft/libft.a
LIBFT_DIR = ../libft

SRC = ft_helper.c ft_printf.c ft_printnbr.c ft_printchr.c ft_printstr.c \
ft_print_adr.c ft_print_unsigned.c ft_printx_x.c ft_print_double.c debug.c
OBJ = $(SRC:.c=.o)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

all:$(NAME)

$(NAME):$(OBJ)
	cp $(LIBFT_PATH_LIB) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean:
	rm -f $(NAME) $(OBJ)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
