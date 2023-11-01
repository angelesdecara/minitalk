CC=gcc

RM = rm -f

IDIR = include/
IFLAGS := $(addprefix -I,$(IDIR))
INCL := $(subst $(IDIR)/,,$(wildcard include/*.h))
CFLAGS := -Wall -Werror -Wextra -I $(IDIR) 

SRCDIR = src
OBJDIR = obj

SRC_FILES = ft_atoi.c \
	   ft_lstnew_bonus.c \
	   ft_strdup.c \
	   ft_bzero.c ft_lstsize_bonus.c \
	   ft_striteri.c ft_calloc.c	\
   	   ft_memchr.c	ft_strjoin.c \
	   ft_isalnum.c ft_memcmp.c \
	   ft_strlcat.c ft_isalpha.c \
	   ft_memcpy.c ft_strlcpy.c ft_isascii.c \
       ft_memmove.c ft_strlen.c ft_isdigit.c	\
	   ft_memset.c ft_strmapi.c ft_isprint.c	\
   	   ft_printf.c ft_strncmp.c ft_itoa.c \
	   ft_putchar_fd.c ft_strnstr.c ft_lstadd_back_bonus.c \
   	   ft_putendl_fd.c ft_strrchr.c ft_lstadd_front_bonus.c \
	   ft_putnbr_base.c ft_strtrim.c ft_lstclear_bonus.c \
   	   ft_putnbr_fd.c ft_substr.c ft_lstdelone_bonus.c \
   	   ft_putptr.c ft_tolower.c ft_lstiter_bonus.c \
   	   ft_putstr_fd.c ft_toupper.c ft_lstlast_bonus.c \
	   ft_split.c ft_uint.c ft_lstmap_bonus.c \
	   ft_strchr.c get_next_line.c

NAME = libft.a
SRCS = $(addprefix $(SRCDIR)/, $(SRC_FILES))

OBJ_FILES := $(SRC_FILES:%.c=%.o)
OBJS = $(addprefix $(OBJDIR)/, $(OBJ_FILES))

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p 2> /dev/null

${NAME}: ${OBJS}
	ar rc $(NAME) $(OBJS)

all: $(NAME)  
	ar rc $(NAME) ${OBJS} 
	
clean:
	${RM} ${OBJS} 

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
