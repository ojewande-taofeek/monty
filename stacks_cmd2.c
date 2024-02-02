#include "monty.h"

/**
 * add - Adds data to the top of stack
 * @head: Top of stack
 * @line_number: The line number of tokenized command
 * Return: Always nothing
 */

void add(stack_t **head, unsigned int line_number)
{
	int counter, added;
	stack_t *current = *head;

	for (counter = 0; current != NULL; counter++)
		current = current->next;
	if (counter < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = *head;
	added = current->n + current->next->n;
	current->next->n = added;
	current->next->prev = NULL;
	(*head) = current->next;
	free(current);
}

/**
 * nop - does nothing
 * @head: Top of stack
 * @line_number: The line number of tokenized command
 * Return: Always nothing
 */

void nop(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}
