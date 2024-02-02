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

/**
 * sub - subtracts data to the top of stack
 * @head: Top of stack
 * @line_number: The line number of tokenized command
 * Return: Always nothing
 */

void sub(stack_t **head, unsigned int line_number)
{
	int subtract;
	stack_t *current = *head;

	if (!(current && current->next))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	subtract = (current->next->n) - (current->n);
	current->next->n = subtract;
	(*head) = current->next;
	(*head)->prev = NULL;
	free(current);
}

/**
 * div - divides the second top element of the stack
 *       by the top element of the stack
 * @head: Top of stack
 * @line_number: The line number of tokenized command
 * Return: Always nothing
 */

void div(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (!(current && current->next))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	current->next->n = (current->next->n) / (current->n);
	(*head) = current->next;
	(*head)->prev = NULL;
	free(current);
}
