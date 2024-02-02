#include "monty.h"

/**
 * check_digits - Function that checks number
 * @str: The str to be checked
 * Return: True, if a number and False if otherwise
 */

bool check_digits(char *str)
{
	char *endptr;

	strtol(str, &endptr, 10);
	return (*endptr == '\0');
}


/**
 * free_stack - Function to free all nodes on stacks
 * @head: Top of stack
 * Return: Always Nothing
 */

void free_stack(stack_t **head)
{
	stack_t *current = *head;
	stack_t *tmp = NULL;

	if (*head)
	{
		while (current)
		{
			tmp = current->next;
			free(current);
			current = tmp;
		}
	}
}

/**
 * _strdup - The function returns a pointer to a newly allocated space in
 *           memory, which conatins a copy of the string given as a parameter
 * @str: The string constant formal parameter
 * Return: A pointer to the duplicated string
 */

char *_strdup(char *str)
{
	int idx = 0;
	char *dup;

	if (str == NULL)
	{
		dup = NULL;
		return (dup);
	}
	dup = (char *) malloc((strlen(str) + 1) * sizeof(char));
	if (dup == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (*str)
	{
		*(dup + idx) = *(str);
		idx++;
		str++;
	}
	return (dup);
}
