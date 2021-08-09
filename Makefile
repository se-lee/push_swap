HEADER	=	push_swap.h
SRCS	=	checks.c\
			list_stack_utils.c\
			get_numbers.c\
			op_swap.c\
			op_rotate.c\
			op_rev_rotate.c\
			op_push.c\
			preps.c\
			sort_three.c\
			sort_five.c\
			sort_big.c\
			bubble_sort.c\
			main.c\

OBJS	= $(SRCS:.c=.o)
NAME	= push_swap
LIBFT	= libft
LIBFT_FILE	= $(LIBFT)/libft.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
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
