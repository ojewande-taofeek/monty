#include "monty.h"

/**
 * push - Adds data to the top of stack
 * @head: Top of stack
 * @line_number: The line number of tokenized command
 * Return: Always nothing
 */


void push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node;
	char *delm = " \v\b\t\r\n", *line_token;
	int number;

	line_token = strtok(NULL, delm);
	if (line_token == NULL || !check_digits(line_token))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	number = atoi(line_token);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	call_push(new_node, number, head);
}


/**
 * pall - print all data on stack
 * @head: Top of stack
 * @line_number: The line number of tokenized command
 * Return: Always nothing
 */


void pall(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	(void) line_number;

	if (*head == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - print data at the top of stack
 * @head: Top of stack
 * @line_number: The line number of tokenized command
 * Return: Always nothing
 */

void pint(stack_t **head, unsigned int line_number)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop - removes the top element of the stack
 * @head: Top of stack
 * @line_number: The line number of tokenized command
 * Return: Always nothing
 */

void pop(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head) = current->next;
	free(current);
}

/**
 * swap - swaps the top two elements of the stack
 * @head: Top of stack
 * @line_number: The line number of tokenized command
 * Return: Always nothing
 */

void swap(stack_t **head, unsigned int line_number)
{
	int counter;
	stack_t *current, *tmp;

	current = *head;
	for (counter = 0; current != NULL; counter++)
	{
		current = current->next;
	}
	if (counter < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = *head;
	tmp = (*head)->next;
	current->next = tmp->next;
	current->prev = tmp;
	tmp->next = current;
	tmp->prev = NULL;
	if (current->next != NULL)
		current->next->prev = current;
	*head = tmp;
}
