
#include "push_swap.h"

void sort_a_3_alone(t_stack *a)
{
	int first; 
	int second;
	int third;
	
	first = a->top->content;
	second = a->top->next->content;
	third = a->bottom->content;
	if (first < second)
	{
		if (first > third)
			op_reverse_rotate_a(a);
		else // if (first < third)
		{
			op_reverse_rotate_a(a);
			op_swap_a(a);
		}
	}
	else // if (first > second)
	{
		if (second > third)
			op_reverse_rotate_a(a);
		else // if (second < third)
		{
			if (first > third)
				op_rotate_a(a);
			else //if (first < third)
				op_swap_a(a);
		}
	}
}

void	sort_a_3_not_alone(t_stack *a)
{
	int first; 
	int second;
	int third;
	
	first = a->top->content;
	second = a->top->next->content;
	third = a->bottom->content;


}
