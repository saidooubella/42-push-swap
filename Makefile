
CC=cc
FLAGS=-Wall -Wextra -Werror
NAME=push_swap

INCLUDES=ft_atoi.h ft_string_utils.h ft_utilities.h push_swap.h stack.h stacks.h

COMMON_SRCS=ft_atoi.c ft_string_utils.c ft_utilities.c get_next_line.c \
get_next_line_utils.c push_swap_.c push_swap__.c push_swap___.c push_swap____.c \
push_swap_____.c push_swap______.c stack.c stack_utils.c stacks.c stacks_.c stacks__.c

MANADATORY_SRCS=$(COMMON_SRCS) push_swap.c

BONUS_SRCS=$(COMMON_SRCS) checker_bonus.c

MANADATORY_OBJS=$(MANADATORY_SRCS:.c=.o)

BONUS_OBJS=$(BONUS_SRCS:.c=.o)

$(NAME): $(MANADATORY_OBJS)
	$(CC) $^ -o $@

%.o: %.c $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $^ -o checker

clean:
	rm -rf $(MANADATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME) checker

re: fclean all

.PHONY: all bonus clean fclean re
