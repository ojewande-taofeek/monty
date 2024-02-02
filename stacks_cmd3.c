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

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @head: Top of stack
 * @line_number: The line number of tokenized command
 * Return: Always nothing
 */

void pchar(stack_t **head, unsigned int line_number)
{
	int num;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = (*head)->n;
	if ((num < 0 || num > 127))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", num);
}


/**
 * pstr - prints the string starting at the top of the stack,
 *        followed by a new line
 * @head: Top of stack
 * @line_number: The line number of tokenized command
 * Return: Always nothing
 */

void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	(void) line_number;

	if (!(*head))
	{
		putchar('\n');
		return;
	}
	current = *head;
	while (current && current->n != 0)
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
