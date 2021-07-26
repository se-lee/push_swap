#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		node_count;
}				t_stack;

void	init_stack(t_stack *stack);
void	add_to_stack_back(t_stack *stack, t_node *new_node);
void	print_list(t_stack *stack);  //erase this later
void	init_stack(t_stack *stack);
void	add_to_stack(t_stack *stack, t_node *new_node); //push
void	store_to_stack(char **argv);


#endif
