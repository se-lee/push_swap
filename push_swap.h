#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"


//each element in the linked list
typedef struct s_list
{
	int				*content;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

//stack
typedef struct s_stack
{
	t_list	*top;
	t_list	*bottom;
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
