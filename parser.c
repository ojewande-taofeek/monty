#include "monty.h"

/**
 * parser - The function parses the each line of the file
 * @buf_cpy: A copy of each line in file
 * @line_number: The file line_number
 * @top: Top of the stack
 * Return: Always nothing
 */

void parser(char *buf_cpy, size_t line_number, stack_t **top)
{
	char *buf, *token, *delm = " \t", **buf_array;
	unsigned int count = 0, idx;

	buf = _strdup(buf_cpy);
	if (buf == NULL)
		check_malloc();
	token = strtok(buf, delm);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delm);
	}
	if (count == 0)
		return;
	free(buf);
	buf_array = malloc(sizeof(char *) * count);
	if (buf_array == NULL)
		check_malloc();
	buf = _strdup(buf_cpy);
	if (buf == NULL)
		check_malloc();
	token = strtok(buf, delm);
	for (idx = 0; token != NULL; idx++)
	{
		buf_array[idx] = _strdup(token);
		if (buf_array[idx] == NULL)
		{
			free(buf);
			free(buf_array);
			check_malloc();
		}
		token = strtok(NULL, delm);
	}
	cmd_cmp(buf_array, line_number, count, top);
	free(buf);
}
