

#include "push_swap.h"

static void sort_b_3_alone(t_stack *b)
{
	int first; 
	int second;
	int third;
	
	first = b->top->content;
	second = b->top->next->content;
	third = b->bottom->content;
	if (first > second)
	{
		if (first < third)
			op_reverse_rotate_b(b);
		else if (third > second)
		{
			op_reverse_rotate_b(b);
			op_swap_b(b);
		}
	}
	else
	{
		if (first > third)
			op_swap_b(b);
		else if (second > third)
			op_rotate_b(b);
		else
		{
			op_swap_b(b);
			op_reverse_rotate_b(b);
		}
	}
}

static void	sort_b_3_not_alone(t_stack *b)
{
	int first; 
	int second;
	int third;
	
	first = b->top->content;
	second = b->top->next->content;
	third = b->top->next->next->content;

	if (first > second)
	{
		if (first < third)
		{
			op_rotate_b(b);
			op_swap_b(b);
			op_reverse_rotate_b(b);
			op_swap_b(b);
		}
		else if (third > second)
		{
			op_rotate_b(b);
			op_swap_b(b);
			op_reverse_rotate_b(b);
		}
	}
	else
	{
		if (first > third)
			op_swap_b(b);
		else if (second > third)
		{
			op_swap_b(b);
			op_rotate_b(b);
			op_swap_b(b);
			op_reverse_rotate_b(b);
		}
		else
		{
			op_swap_b(b);
			op_rotate_b(b);
			op_swap_b(b);
			op_reverse_rotate_b(b);
			op_swap_b(b);
		}
	}
}

void sort_b_3(t_stack *b)
{
	if (b->node_count == 3)
		sort_b_3_alone(b);
	else
		sort_b_3_not_alone(b);
}
