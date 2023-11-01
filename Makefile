
CC = gcc
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I ./$(INCDIR) -L libft
RM = rm -f

SRCS = client.c server.c
OBJS = $(SRCS:%.c = %.o)

LIB = libft/libft.a

SNAME = server
CNAME = client

$(OBJS)/%.o = $(SRCS)/%.c

server:
	@make -C libft
	@$(CC) $(CFLAGS) $(LIB) server.c -o $(SNAME)

client:
	@make -C libft
	@$(CC) $(CFLAGS) $(LIB) client.c -o $(CNAME)

all:
	@make -C libft
	$(OBJS)

clean:
	@make clean -C libft
	$(RM) *.o 

fclean:
	clean
	$(RM) $(NAME)

re: fclean all
