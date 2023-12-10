
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRC = ft_atoi.c ft_bzero.c ft_putchar.c ft_putnbr_base.c ft_putptr.c ft_uint.c ft_printf.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr.c
OBJ = $(SRC:%.c=%.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

LIB = ar rc $(NAME) $(OBJ)

$(OBJ): $(SRC)
	@ $(CC) $(CFLAGS) -c $(SRC)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean
