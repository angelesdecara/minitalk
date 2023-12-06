
CC = gcc
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I ./$(INCDIR) -L lib
RM = rm -f

SRCS = client.c server.c
OBJS = $(SRCS:%.c = %.o)

LIB = libft/lib.a

SNAME = server
CNAME = client
NAME = minitalk

all: $(LIB) $(SNAME) $(CNAME)

$(LIB): 
	@make -C libft/

lib:
	@make -C libft/

$(SNAME): 
	@make -C libft
	@$(CC) $(CFLAGS) $(LIB) server.c -o $(SNAME)

$(CNAME):
	@make -C libft
	@$(CC) $(CFLAGS) $(LIB) client.c -o $(CNAME)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) $(LIB) client.c -o $(CNAME)
	@$(CC) $(CFLAGS) $(LIB) server.c -o $(SNAME)


clean:
	@make clean -C libft
	$(RM) *.o server client

fclean:
	clean
	$(RM) $(NAME)

re: fclean all
