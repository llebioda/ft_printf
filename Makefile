CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCFILES = ft_printf.c flags.c format_char.c format_nbr.c format_hex.c
SRCDIR = ./
SRCS = $(addprefix $(SRCDIR), $(SRCFILES))
OBJDIR = ./build/
OBJS = $(addprefix $(OBJDIR), $(SRCFILES:.c=.o))

HEADERFILES = ft_printf.h
HEADERDIR = ./
HEADERS = $(addprefix $(HEADERDIR), $(HEADERFILES))
INCLUDES = -I $(HEADERDIR)

NAME = libftprintf.a

all: $(NAME)
bonus: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
