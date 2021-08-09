#include "push_swap.h"

/*
get mid number,
pb two numbers smaller than mid number,
in stack b, sort big->small
in stack a, do three number sort
pa two numbers
*/

void	sort_two(t_stack *stack)
{
	if (stack->top->content < stack->top->next->content)
		sb(stack);
}

int		get_mid_nbr_five(t_node *node)
{
	int	i;
	int	nbr[5];

	i = 0;
	while(i < 5)
	{
		nbr[i] = node->content;
		node = node->next;
		i++;
	}
	bubble_sort(nbr, 5);
	return (nbr[2]);
}

int		get_avg_nbr(t_stack *stack)
{
	int	avg;
	int	min;
	int	max;

	min = get_min_nbr(stack);
	max = get_max_nbr(stack);
	avg = (min + max) / 2;
	return (avg);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	mid;
	int	pb_count;

	mid = get_mid_nbr_five(stack_a->top);
	pb_count = 0;
	while (stack_a)
	{
		if (stack_a->top->content < mid)
		{
			pb(stack_a, stack_b);
			pb_count++;
		}
		else
			ra(stack_a);
		if (pb_count == 2)
			break;	
	}
	sort_three_args(stack_a);
	sort_two(stack_b);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}
/*

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int	mid;

	init_stack(&a);
	init_stack(&b);
	store_to_stack(argv, &a);
	print_list(&a);
	print_list(&b);
	mid = get_mid_nbr_five(a.top);
	printf("mid: %d\n", mid);
	sort_five(&a, &b);

	printf("after:\n");
	print_list(&a);
	print_list(&b);

	return (0);
}

*/