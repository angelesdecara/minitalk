
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = minitalk
SRC = server.c client.c
OBJ = $(SRC:%.c=%.o)

all: server client

lib: 
	$(MAKE) -C libft

server: server.o lib
	@$(CC) -o $@ $< -Llibft -lft

client: client.o lib
	@$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS)  $?

clean:
	@make clean -C libft
	$(RM) $(OBJ) 

fclean: clean
	@make fclean -C libft
	$(RM) server client

re: fclean all
.PHONY: all fclean re all
