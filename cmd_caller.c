#include "monty.h"

/**
 * cmd_caller - A funtion pointer that calls the required cmd
 * @cmd: The command to call
 * @count: The number of elements in a line
 * @stack: The top of the stack
 * @line_number: The file line number where the command is called
 * Return: The specified function if successful
 *          NULL, if otherwise
 */
 
void (*cmd_caller(char **buf_arr, unsigned int count, unsigned int line_number)
		)(stack_t **stack, char **buf_arr)
{
	int idx = 0;
	char *cmd = buf_arr[0];

	instruction_t call[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
	};

	for (idx = 0; call[idx].opcode != NULL; idx++)
	{
		if (strcmp(call[idx].opcode, cmd) == 0)
		{
			if ((strcmp(cmd, "push") == 0) && count != 2)
			{				
				fprintf(stderr, "L%d : unknown instruction %s\n", line_number, cmd);
				exit(EXIT_FAILURE);
			}
			return (call[idx].f);
		}
	}
	return (NULL);
}
