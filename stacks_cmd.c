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
	new_node->n = number;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
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
