#include "push_swap.h"

void	push_small_to_b(t_stack *stack_a, t_stack *stack_b, t_pivcount *pvcnt)
{
	int		temp;

//	cursor = stack_a->top;
	temp = stack_a->node_count;
	get_pivot(stack_a->top, stack_a->node_count, pvcnt);
	printf("[pb]piv_big: %d  piv_s: %d \n", pvcnt->piv_big, pvcnt->piv_small);
	while (temp > 0)
	{
		if (stack_a->top->content <= pvcnt->piv_big)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		temp--;
	}
}

void	a_to_b_test(t_stack *stack_a, t_stack *stack_b, int range)
{
	t_pivcount	pvcnt;

	get_pivot(stack_a->top, range, &pvcnt);
	push_small_to_b(stack_a, stack_b, &pvcnt);
}

void	push_big_to_a(t_stack *stack_a, t_stack *stack_b, t_pivcount *pvcnt)
{
	int	temp;

	temp = stack_b->node_count;
	printf("[pa_piv]B: %d   S: %d\n", pvcnt->piv_big, pvcnt->piv_small);
	while (temp > 0)
	{
		if (stack_b->top->content > pvcnt->piv_big)
		{
			pa(stack_b, stack_a);
			pvcnt->pa++;
		}
		else
			rb(stack_b);
		temp--;
	}
}

void	sort_b_pa(t_stack *stack_a, t_stack *stack_b, int range)
{
	t_pivcount pvcnt;
	int temp;

	temp = range;
	get_pivot(stack_b->top, stack_b->node_count, &pvcnt);
	printf("[to a]pivB: %d   pvS: %d  \n", pvcnt.piv_big, pvcnt.piv_small);
	push_big_to_a(stack_a, stack_b, &pvcnt);

}


// void	quick_sort_b(t_stack *stack)
// {

// }





/*

引数50個あたえられたとします。

void	sort_over6(t_dlst *a, t_dlst *b, t_ps *ps)
{
	long	size;
    
    // 半々にわけます。 A:26~50, B:1~25
	half_set(a, b, ps);

	while (ps->awant != ps->size)
	{
		b_settle_top(a, b, ps);

        // Bの要素が4個以下になるまで、Bを半分にわけます。
        // A:13~24 + 25~50              B:1~12 
        // A:7~12 + 13~24 + 25~50       B:1~6 
        // A:4~6 + 7~12 + 13~24 + 25~50 B:1~3 
		while ((size = dlst_size(b)) > SORTSIZE)
			b_quick_sort(a, b, ps, size);
		if (size)
			allsort(a, b, ps, size);

        // Aは、3個、6個、12個、と部分でまとまった並びになっています。
        // まとまりが4個以下ならソート順に確定。
        // 5個以上なら、全部Bにうつします。
		while ((size = search_a_size(a, ps)) && size <= SORTSIZE)
			allsort(a, b, ps, size);
		if (size)
			a_quick_sort(a, b, ps, size);
	}
}

*/