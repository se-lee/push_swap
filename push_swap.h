#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"


//each element in the linked list
typedef struct s_node
{
	int				*content;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

//stack
typedef struct s_stack
{
	t_node	*top;  //points to the top node
	t_node	*bottom; //points to the bottom node
}				t_stack;

/*check*/
/*prep*/
/*sorting*/
/*display*/

/* questions to solve:
- linked list functions from libft -- struct defined in libft header and push_swap header/
	-> if i use libft functions, will it use struct from libft.h? or push_swap.h??




*/


#endif
