#include "monty.h"

/**
 * call_push - push to the stack based on mode
 * @head: Top of stack
 * @new_node: The new element to be pushed to stack
 * @number: value of data to be pushed
 * Return: Always nothing
 */


void call_push(stack_t *new_node, int number, stack_t **head)
{
	stack_t *current;

	new_node->n = number;
	new_node->prev = NULL;
	if (strcmp(mode, "stack") == 0)
	{
		new_node->next = *head;
		if (*head != NULL)
		{
			(*head)->prev = new_node;
		}
		*head = new_node;
	}
	else
	{
		new_node->next = NULL;
		current = *head;
		if (*head == NULL)
		{
			*head = new_node;
			return;
		}
		while (current->next)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
}


