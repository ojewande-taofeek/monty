#include "monty.h"
/**
 * add - A function that adds the top two elements on the stack
 * @stack: Pointer to the stack
 * @line_number: Line number
 * Return: Nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - This ia an opcode that doesn't do anything
 * from the second top
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: Nothing
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - An opcode that subtracts top elements on the stack
 * @stack: pointer to the stack
 * @line_number: Line number
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	/*int result;*/

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
/*	result = ((*stack)->next->n - ((*stack)->n)) * -1; */
/*	(*stack)->next->n = result */
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * div - The opcode that divides the top elements on the stack
 * @stack: Pointer to the stack
 * @line_number: Line number
 * Return: Nothing
 */

void div(stack_t **stack, unsigned int line_number)
{
	/*int result;*/

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

/*	result = ((*stack)->n / (*stack)->next->n);*/
/*	(*stack)->next->n = result; */
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - The opcode that multiplies the top two elements on the stack
 * @stack: A pointer to the stack
 * @line_number: Line number
 * Return: Nothing
 */

void mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
