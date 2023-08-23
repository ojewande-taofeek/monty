#include "monty.h"

/**
 * cmd_caller - A funtion pointer that calls the required cmd
 * @b: The array of buffer
 * @cnt: The number of element in buffer
 * @line: line number of cmd
 * Return: The specified function if successful
 *          NULL, if otherwise
 */
void (*cmd_caller(char **b, size_t cnt, size_t line))(stack_t **top, char **b)
{
	int idx = 0;
	char *cmd = b[0];

	instruction_t call[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
	};

	for (idx = 0; call[idx].opcode != NULL; idx++)
	{
		if (strcmp(call[idx].opcode, cmd) == 0)
		{
			if ((strcmp(cmd, "push") == 0) && cnt != 2)
			{
				fprintf(stderr, "L%ld: usage: push integer\n", line);
				exit(EXIT_FAILURE);
			}
			return (call[idx].f);
		}
	}
	return (NULL);
}
