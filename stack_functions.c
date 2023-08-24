#include "monty.h"
/**
 * create_node - The function creates a new node
 * @n: The data to be stored in the new node
 * Return: A new node
 */

stack_t *create_node(int n)
{
	stack_t *new_Node = malloc(sizeof(stack_t));

	if (new_Node == NULL)
		check_malloc();
	new_Node->n = n;
	new_Node->prev = NULL;
	new_Node->next = NULL;

	return (new_Node);
}

/**
 * is_empty - The fucntion checks if the top point to NULL
 * @stack: The top of the stack
 * Return: 1, if True
 *         0, if otherwise
 */

int is_empty(stack_t *stack)
{
	return (!stack);
}

/**
 * push - The function that push to the top of the stack
 * @stack: The top of the stack
 * @line: The line number
 * Return: Nothing
 */

void push(stack_t **stack, unsigned int line)
{
	int data;
	stack_t *new_node;
	char *num = strtok(NULL, " \n");

	if (num == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	data = atoi(num);
	if (data == 0 && (strcmp(num, "0") != 0))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	new_node = create_node(data);

	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
/**
 * pall - The function prints the elements in a stack
 * @stack: The top of the stack
 * @line: The line number
 * Return: Nothing
 */

void pall(stack_t **stack, unsigned int line)
{
	stack_t *current = *stack;
	(void) line;


	if (is_empty(current))
		return;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pint - The function prints the top of a stack
 * @stack: The top of the stack
 * @line: The line number
 * Return: Nothing
 */

void pint(stack_t **stack, unsigned int line)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", current->n);
}
