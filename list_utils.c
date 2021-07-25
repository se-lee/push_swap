#include "push_swap.h"

//init element
t_node	*ft_new_node(void *content)
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

//erase libft functions later
void	ft_lstadd_front(t_node **lst, t_node *new)
{
	(*new).next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
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

t_node	*ft_lstlast(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while ((*lst).next != NULL)
		lst = (*lst).next;
	if ((*lst).next == NULL)
		return (lst);
	return (NULL);
}

void init_stack(t_stack *stack, t_node *node)
{
	stack->top = node//top node
	stack->bottom = node//bottom node
}

// a function to do atoi and store again to argv[i];


int main(int argc, char **argv)
{
	int i;

	i = 0;
	
	while (argv[i] != NULL)
	{
		ft_atoi(argv[i]); //need 
		i++;
	}

	i = 0;
	while (argv[i] != NULL)
	{
		printf("arg[%d]: %d\n", i, argv[i]);
		i++;
	}
}



/*prep*/
//prepare stacks a and b
//create linked list, circular, going both ways
//store each argument to each node and put them into stack a

