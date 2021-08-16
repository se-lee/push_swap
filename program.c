#include "push_swap.h"

char* instruction_names[12] = {
	"pa", "pb",
	"ra", "rb", "rr",
	"sa", "sb", "ss",
	"rra", "rrb", "rrr",
};

void	program_init(t_program *program)
{
	program->first = NULL;
	program->last = NULL;
}

void	program_add_instruction(t_program *program, t_instruction instruction)
{
	t_program_node* node;
	
	node = malloc(sizeof(t_program_node));
	node->instruction = instruction;
	node->next = NULL;
	if (program->first == NULL)
		program->first = node;
	else
		program->last->next = node;
	program->last = node;
}

static int instruction_cancel_each_other(t_instruction a, t_instruction b)
{
	return ((a == pa && b == pb) || (a == pb && b == pa)
		|| (a == ra && b == rra) || (a == rra && b == ra)
		|| (a == rb && b == rrb) || (a == rrb && b == rb)
		|| (a == sa && b == sa) || (a == sb && b == sb));
}

static void program_remove_useless(t_program *program)
{
	t_instruction a;
	t_instruction b;
	t_program_node	**cursor;
	t_program_node	*rest;
	t_program_node	**previous;

	previous = NULL;
	cursor = &program->first;
	while (*cursor != NULL && (*cursor)->next != NULL)
	{
		a = (*cursor)->instruction;
		b = (*cursor)->next->instruction;
		if (instruction_cancel_each_other(a, b))
		{
			rest = (*cursor)->next->next;
			free((*cursor)->next);
			free(*cursor);
			if (previous != NULL)
				cursor = previous;
			else
				*cursor = rest;
		}
		else
		{
			previous = cursor;
			cursor = &(*cursor)->next;
		}
	}
}

void	program_optimize(t_program *program)
{
	program_remove_useless(program);
}

void	program_run(t_program *program)
{
	t_program_node	*cursor;

	cursor = program->first;
	while (cursor != NULL)
	{
		ft_putendl_fd(instruction_names[cursor->instruction], 1);
		cursor = cursor->next;
	}
}

void	program_free(t_program *program)
{
	t_program_node	*cursor;
	t_program_node	*to_free;

	cursor = program->first;
	while (cursor != NULL)
	{
		to_free = cursor;
		cursor = cursor->next;
		free(to_free);
	}
}