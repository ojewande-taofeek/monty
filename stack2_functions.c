#include "monty.h"


/**
 * pop - The function removes the top of the stack
 * @stack: The stack
 * @line: Line number of cmd
 * Return: Nothing
 */

void pop(stack_t **stack, unsigned int line)
{

	stack_t *tmp;
	stack_t *current = *stack;

	if (is_empty(current))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	tmp = current;
	current = current->next;
	free(tmp);
}
