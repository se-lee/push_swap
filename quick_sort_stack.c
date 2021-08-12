#include "push_swap.h"

/*
pb all smaller&equal numbers than pivot
sort a (and forget everthing under) small->big
sort b big->small

once two stacks are sorted, do pa
try not to touch other parts
* i need to know from where to where (= the range of the part i want to take care of) 
reset
-> count the number of ra then do rra
-> count the number of rb, then do rrb
*/

// int range is the part where i want to sort
void	pb_small_ra(t_stack *stack_a, t_stack *stack_b, t_pivcount *pvcnt, int range)
{
	int		temp;

	temp = range; //eg. node count
 printf("temp(range): %d    ", temp);

	while (temp > 0)
	{
		if (stack_a->top->content <= pvcnt->pivot)
		{
			pb(stack_a, stack_b);
			pvcnt->pb++; //pb count will be the sorting range in stack_b
		}
		else if (stack_a->top->content > pvcnt->pivot)
		{
			ra(stack_a);
			pvcnt->ra++;
		}
		temp--;
	}
	temp = pvcnt->ra;
	while (temp > 0)
	{
		rra(stack_a);
		temp--;
	}
}

void	pa_big_rb(t_stack *stack_a, t_stack *stack_b, t_pivcount *pvcnt, int range)
{
	int	temp;

	temp = range;
	while (temp > 0)
	{
		if (stack_b->top->content > pvcnt->pivot)
		{
			pa(stack_b, stack_a);
			pvcnt->pa++;
		}
		else
		{
			rb(stack_b);
			pvcnt->rb++;
		}
		temp--;
	}
	temp = pvcnt->rb;
	while (temp > 0)
	{
		rrb(stack_b);
		temp--;
	}
}


void	a_to_b_sort(t_stack *stack_a, t_stack *stack_b, int range)
{
	t_pivcount	pvcnt;
	
	init_op_count(&pvcnt);
	get_pivot(stack_a->top, range, &pvcnt); //get pivot from the given range
// printf("[a_piv] %d \n", pvcnt.pivot);
	pb_small_ra(stack_a, stack_b, &pvcnt, range);
// sort a: a_sort_three(stack_a); // how do i know the range is three

}

void	b_to_a_sort(t_stack *stack_a, t_stack *stack_b, int range)
{
	t_pivcount pvcnt;

	get_pivot(stack_b->top, stack_b->node_count, &pvcnt);
 printf("[b]piv: %d \n", pvcnt.pivot);
	pa_big_rb(stack_a, stack_b, &pvcnt, range);
/* sort b in reverse order: b_sort_three(stack_b);  */


}


/*

Aを半分→半分→半分・・・にして
小さくなったらソートする
Bスタックからピボット選んで大きいやつをAにんプッシュする
プッシュされた分のレンジをソートする
ーーーのくりかえし
sort: half & sort left & sort right & merge
        


＝＝＝＝＝

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