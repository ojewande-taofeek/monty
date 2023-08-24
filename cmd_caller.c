#include "monty.h"

/**
 * cmd_caller - A funtion pointer that calls the required cmd
 * @cmd: The cmd to execute
 * @line: The line number
 * @top: The top of stack
 * Return: The specified function if successful
 *          NULL, if otherwise
 */
void cmd_caller(char *cmd, unsigned int line, stack_t **top)
{
	int idx = 0;


	instruction_t call[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};


	for (idx = 0; call[idx].opcode != NULL; idx++)
	{
		if (strcmp(call[idx].opcode, cmd) == 0)
		{
			call[idx].f(top, line);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, cmd);
	exit(EXIT_FAILURE);
}
