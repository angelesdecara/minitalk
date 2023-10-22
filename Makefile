
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I ./$(INCDIR) -L libft
RM = rm -f

SRCS = client.c server.c
OBJS = $(SRCS:%.c = %.o)

LIB = libft/libft.a

$(OBJS)/%.o = $(SRCS)/%.c

all:
	@make -C libft
	$(OBJS)

clean:
	$(RM) $(OBJS)
