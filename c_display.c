#include "push_swap.h"

static void	display_number_width11(int num)
{
	int	ct[2];

	ct[0] = 1;
	if (num < 0)
		ct[0]++;
	ct[1] = num;
	while (ct[1] > 9 || ct[1] < -9)
	{
		ct[0]++;
		ct[1] /= 10;
	}
	ct[0] = 11 - ct[0];
	while (ct[0]--)
		ft_putchar_fd(' ', 1);
	ft_putnbr_fd(num, 1);
}

static void	sub(int ct[3], t_node *cur[2], char *message, t_stack *stack[2])
{
	ct[0] = ft_max(stack[0]->node_count, stack[1]->node_count);
	ct[2] = stack[0]->node_count + stack[1]->node_count - ct[0];
	ft_putendl_fd(message, 1);
	while (ct[2]-- > 0)
		ft_putendl_fd("", 1);
	cur[0] = stack[0]->bottom;
	cur[1] = stack[1]->bottom;
}

void	display_stacks(t_stack *stack[2], char *message)
{
	int				ct[3];
	t_node	*cur[2];

	sub(ct, cur, message, stack);
	while (--ct[0] >= 0)
	{
		if (ct[0] < stack[0]->node_count)
		{
			display_number_width11(*((int *)cur[0]->content));
			cur[0] = cur[0]->next;
		}
		else
			ft_putstr_fd("           ", 1);
		ft_putstr_fd("     ", 1);
		if (ct[0] < stack[1]->node_count)
		{
			display_number_width11(*((int *)cur[1]->content));
			cur[1] = cur[1]->next;
		}
		ft_putendl_fd("", 1);
	}
	ft_putendl_fd("__________a     __________b", 1);
	ft_putendl_fd("---------------------------", 1);
}

// typedef struct s_double_list
// {
// 	void					*content;
// 	struct s_double_list	*next;
// 	struct s_double_list	*last;
// }				t_node;

// typedef struct s_deque
// {
// 	struct s_double_list	*head;
// 	struct s_double_list	*tail;
// 	int						size;
// }				t_stack;