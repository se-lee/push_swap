#include "push_swap.h"

/*check*/
//whether arguments are valid: strings, decimals, no argument, ...what else?
//whether stack arguments are already sorted -> do nothing

int	check_no_arg(int argc)
{// if there is no argument return -1;
	if (argc <= 1)
		return (-1);
}

int	check_non_int(char *arg)
{//check if argument includes non-int values
	int	i;

	i = 0;
	while (arg[i] != NULL)
	{
		if ()
/*
int	ft_isalpha(int c)
int	ft_isascii(int c)
int	ft_isdigit(int c)
...
*/
		i++;
	}
}

int	check_duplicate()
{// if duplicate number is found, return -1;
}

int check_int_max_min()
{//check if the argument is bigger/smaller than int max/min
}
