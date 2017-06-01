NAME = printf

CC = clang

CFLAGS = -I includes -g

CDIR = src

CFILES	=	$(CDIR)/ft_printf.c		\
			$(CDIR)/extract_param.c	\
			main.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(CFILES)

clean:

fclean: clean
	rm -f printf

.PHONY: clean

re: fclean all