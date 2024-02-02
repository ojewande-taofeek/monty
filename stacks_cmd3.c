#include "monty.h"


/**
 * mod - computes the rest of the division the second top element of the stack
 *       by the top element of the stack
 * @head: Top of stack
 * @line_number: The line number of tokenized command
 * Return: Always nothing
 */

void mod(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (!(current && current->next))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	current->next->n %= (current->n);
	(*head) = current->next;
	(*head)->prev = NULL;
	free(current);
}
