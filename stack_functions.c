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
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_Node->n = n;
	new_Node->prev = NULL;
	new_Node->next = NULL;

	return (new_Node);
}

/**
 * push - The function that push to the top of the stack
 * Return: Nothing
 * @stack: The top of the stack
 * @buf_array: An array to get the data from
 */

void push(stack_t **stack, char **buf_array)
{
	int data = atoi(buf_array[1]);
	stack_t *new_node = create_node(data);

	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
/**
 * pall - The function prints the elements in a stack
 * @stack: The top of the stack
 * @buf_array: An array to get the data from
 * Return: Nothing
 */

void pall(stack_t **stack, char **buf_array)
{
	stack_t *current = *stack;
	(void) buf_array;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
