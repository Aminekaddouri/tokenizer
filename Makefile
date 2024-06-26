NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = minishell.c tokenizer.c tokenizer_lst.c tokenizer_utils.c libft.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lreadline

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re