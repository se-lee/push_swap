#include "push_swap.h"

//init element
t_list	*ft_new_node(void *content)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}


void	ft_lstadd_front(t_list **lst, t_list *new)
{
	(*new).next = *lst;
	*lst = new;
}


void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_element;

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


t_list	*ft_lstlast(t_list *lst)
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