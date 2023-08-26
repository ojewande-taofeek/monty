#include "monty.h"

/**
 * pchar - An opcode that prints the character on the stack
 * @stack: Pointer to the stack
 * @line_number: The line number
 * Return: Nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
	/*pop(stack, line_number);*/
}

/**
 * mod - Opcode that get the modulo of the top two elements on the stack
 * @stack: Pointer to the stack
 * @line_number: The line number
 * Return: Nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	/*int result;*/

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*result = (*stack)->n % (*stack)->next->n;*/
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

/**
 * pstr - prints the string on the stack
 * @stack: Pointer to the stack
 * @line_number: The line number
 * Return: Nothing
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *cur;
	(void)line_number;

	cur = *stack;

	while (cur != NULL && cur->n != 0 && (cur->n >= 0 && cur->n <= 127))
	{
		putchar(cur->n);
		cur = cur->next;
	}
	putchar('\n');
}

/**
 * rotl - rotates the stack to the top
 * @stack: Pointer to the stack
 * @line_number: The line number
 * Return: Nothing
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	int num;
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;
		num = (*stack)->n;
		while (last->next != NULL)
		{
			last->n = last->next->n;
			last = last->next;
		}
		last->n = num;
	}
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: Pointer to the stack
 * @line_number: The line number
 * Return: Nothing
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *current;
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		num = current->n;
		while (current->prev != NULL)
		{
			current->n = current->prev->n;
			current = current->prev;
		}
		(*stack)->n = num;
	}
}
