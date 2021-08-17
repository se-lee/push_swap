HEADER	=	push_swap.h
SRCS	=	arg_check.c\
			find_numbers.c\
			main.c\
			op_push.c\
			op_rev_rotate.c\
			op_rotate.c\
			op_swap.c\
			program.c\
			program_optimize.c\
			program_optimize2.c\
			push_swap_utils.c\
			push_swap.c\
			quick_sort_stack_a.c\
			quick_sort_stack_b.c\
			quick_sort.c\
			sort_three_a.c\
			sort_three_rev_b_alone.c\
			sort_three_rev_b_not_alone.c\
			stack_check.c\
			stack_utils.c\

OBJS	= $(SRCS:.c=.o)
NAME	= push_swap
LIBFT	= libft
LIBFT_FILE	= $(LIBFT)/libft.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g
RM		= rm -rf

all:	init $(NAME)

$(NAME): $(OBJS) $(LIBFT_FILE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FILE) -o $(NAME)

$(LIBFT_FILE): init

%.o:	%.c $(HEADER) $(LIBFT)/libft.h
	$(CC) $(CFLAGS) -c $< -Ilibft -o $@

init:
	$(MAKE) -C $(LIBFT)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT) clean
	@ $(RM) objs

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re:	fclean all

.PHONY: all clean fclean re init
