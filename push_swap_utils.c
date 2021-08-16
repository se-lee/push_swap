#include "push_swap.h"

void	init_op_count(t_op_count *count)
{
	count->pa_count = 0;
	count->pb_count = 0;
	count->ra_count = 0;
	count->rb_count = 0;
}

void	print_error_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

