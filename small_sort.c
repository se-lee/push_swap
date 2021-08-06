#include "push_swap.h"

int		get_min_nbr(t_stack *stack)
{
	int	min;
	t_node	*temp;

	min = stack->top->content;
	temp = stack->top;
	while (stack)
	{
		if (temp->content < min)
			min = temp->content;
		if (temp->next)
			temp = temp->next;
		else
			break;
	}
	printf("min: %d  ", min);
	return (min);
}

int		get_max_nbr(t_stack *stack)
{
	int	max;
	t_node *temp;

	max = stack->top->content;
	temp = stack->top;
	while (stack)
	{
		if (temp->content > max)
			max = temp->content;
		if (temp->next)
			temp = temp->next;
		else
			break;
	}
	printf("max: %d  ", max);
	return (max);
}

int		get_mid_nbr(t_stack *stack)
{
	int	mid;
	t_node	*temp;

	mid = 0;
	temp = stack->top;
	while (stack)
	{
		if (temp->content != get_min_nbr(stack) && temp->content != get_max_nbr(stack))
			mid = temp->content;
		if (temp->next)
			temp = temp->next;
		else
			break;
	}
	printf("mid: %d  ", mid);
	return (mid);
}


void	three_args_top_min(t_stack *stack)
{
// need extra cases -- error cases (eg if stack is already sorted),
//	rev_rotate(stack);
	swap(stack);
}

void	three_args_top_mid(t_stack *stack)
{
	if (stack->top->next->content < stack->top->content)
		swap(stack);
	else if (stack->top->next->content > stack->top->content)
		rev_rotate(stack);
}

void	three_args_top_max(t_stack *stack)
{
	int	min;

	min = get_min_nbr(stack);
	if (stack->top->next->content == min)
		rotate(stack);
	else if (stack->top->next->content != min)
	{
		rotate(stack);
		swap(stack);
	}
}

void	sort_three_args(t_stack *stack)
{
	int	min;
	int	mid;
	int	max;

	min = get_min_nbr(stack);
	max = get_max_nbr(stack);
	if (stack->top->content == min)
	{
		if (check_sorted(stack) != -1)
			return ;
		else
			three_args_top_min(stack);
	}
}

int	main(int argc, char **argv)
{
	t_stack stack_a;

	init_stack(&stack_a);
	store_to_stack(argv, &stack_a);
	print_list(&stack_a);
	sort_three_args(&stack_a);
	print_list(&stack_a);

	return (0);
}

