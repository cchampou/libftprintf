NAME = printf

CC = clang

CFLAGS = -I includes -g -Wall -Wextra -Werror

CDIR = src

CFILES	=	$(CDIR)/ft_printf.c				\
			$(CDIR)/parsing/parse_param.c			\
			$(CDIR)/parsing/parse_list_manager.c	\
			$(CDIR)/parsing/spec_checker.c			\
			$(CDIR)/parsing/flags_checker.c			\
			$(CDIR)/parsing/len_checker.c			\
			$(CDIR)/parsing/percent_checker.c		\
			$(CDIR)/parsing/prec_checker.c			\
			$(CDIR)/parsing/width_checker.c			\
			$(CDIR)/treatment/treat.c			\
			$(CDIR)/treatment/args.c			\
			$(CDIR)/treatment/get_args_1.c			\
			$(CDIR)/treatment/get_args_2.c			\
			main.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(CFILES)

clean:
	rm -rf printf.dSYM

fclean: clean
	rm -f printf

.PHONY: clean

re: fclean all
