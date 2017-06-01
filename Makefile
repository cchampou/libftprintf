NAME = printf

CC = clang

CFLAGS = -I includes -g -Wall -Wextra -Werror

CDIR = src

CFILES	=	$(CDIR)/ft_printf.c				\
			$(CDIR)/parse_param.c			\
			$(CDIR)/parse_list_manager.c	\
			$(CDIR)/conv_checker.c			\
			$(CDIR)/flags_checker.c			\
			$(CDIR)/mod_checker.c			\
			$(CDIR)/percent_checker.c		\
			$(CDIR)/prec_checker.c			\
			$(CDIR)/width_checker.c			\
			main.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(CFILES)

clean:

fclean: clean
	rm -f printf

.PHONY: clean

re: fclean all