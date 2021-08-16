HEADER	=	push_swap.h
SRCS	=	arg_check.c\
			find_numbers.c\
			op_push.c\
			op_rev_rotate.c\
			op_rotate.c\
			op_swap.c\
			program.c\
			push_swap_utils.c\
			push_swap.c\
			quick_sort_stack_a.c\
			quick_sort_stack_b.c\
			quick_sort.c\
			sort_three_a.c\
			sort_three_rev_b.c\

			stack_check.c\
			stack_utils.c\
			sort_upto_three.c\
			sort_upto_three_rev.c\
			sort_upto_five.c\
			aaaa.c\
			main.c\

OBJS	= $(SRCS:.c=.o)
NAME	= push_swap
LIBFT	= libft
LIBFT_FILE	= $(LIBFT)/libft.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g # -D DEBUG
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
