#include "push_swap.h"

//init element
t_node	*ft_new_node(int content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->node_count = 0;
}

void add_to_stack(t_stack *stack, t_node *new_node) //push
{
	if (stack->top == NULL)
		stack->top = new_node;
	else
	{
		new_node->next = stack->top;
		stack->top = new_node;
	}
}

/*------erase libft functions later--------
void	ft_lstadd_front(t_node **lst, t_node *new)
{//Adds the element ’new’ at the beginning of the list.
	(*new).next = *lst;
	*lst = new;
}

t_node	*ft_lstlast(t_node *lst)
{//Returns the last element of the list.
	if (lst == NULL)
		return (NULL);
	while ((*lst).next != NULL)
		lst = (*lst).next;
	if ((*lst).next == NULL)
		return (lst);
	return (NULL);
}

void	ft_lstadd_back(t_node **lst, t_node *new) //lst is the first element
{//Adds the element ’new’ at the end of the list.
	t_node	*last_element;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_element = ft_lstlast(*lst);
	(*last_element).next = new;
}

----------------------------------------*/


// int main(int argc, char **argv)
// {
// 	int i;

// 	i = 0;
	
// 	while (argv[i] != NULL)
// 	{
// 		printf("arg[%d]: %s\n", i, argv[i]);
// 		i++;
// 	}
// }
