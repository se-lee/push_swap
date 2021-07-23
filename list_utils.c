#include "push_swap.h"

//init element
t_node	*ft_new_node(void *content)
{
<<<<<<< HEAD
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
=======
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
>>>>>>> c50e22777fa6e1562b8927a7b26df43c29c6ed0a
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

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



/*prep*/
//prepare stacks a and b
//create linked list, circular, going both ways
//store each argument to each node and put them into stack a

