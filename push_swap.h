#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	t_node	*top;  //points to the top node
	t_node	*bottom; //points to the bottom node
	int		node_count;
}				t_stack;

void init_stack(t_stack *stack);
t_node	*ft_new_node(int content);

/* questions:
- linked list functions from libft -- struct defined in libft header and push_swap header/
	-> if i use libft functions, will it use struct from libft.h? or push_swap.h??

- circular linked list -- how to tell top and bottom

*/


#endif
