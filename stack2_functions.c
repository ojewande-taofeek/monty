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

/**
 * swap - Swaps the topmost elements of stack
 * @stack: The stack
 * @line: Line number of cmd
 * Return: Nothing
 */

void swap(stack_t **stack, unsigned int line)
{
	int tmp, tmp2;
	stack_t *current = *stack;
	int count = 0;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	tmp  = current->n;
	tmp2 = current->next->n;
	current->n = tmp2;
	current->next->n = tmp;
}
