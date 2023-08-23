#include "monty.h"
/**
 * cmd_cmp - The function that checks the command in the bytecode
 * @buf_array: A pointer to pinter of each cmd in a line
 * @line_number: The line number where the cmd is in the file
 * @count: Number of elements per line, max 2 for push and 1 or 0 for the rest
 * Return: Nothing
 */

void cmd_cmp(char **buf_array, unsigned int line_number,
		unsigned int count, stack_t **top)
{
	char *cmd[] = {"push", "pall", NULL};
	unsigned int idx;

	for (idx = 0; cmd[idx] != NULL; idx++)
	{
		if (strcmp(cmd[idx], buf_array[0]))
		{
			cmd_caller(buf_array, count, line_number)(top, buf_array);
			break;
		}

	}		
}
