#include "monty.h"

/**
 * cmd - The function selects the right function
 * @head: Top of stack
 * @line_tok: The command tokenized
 * @line_number: The line number of tokenized command
 * Return: Always nothing
 */

void cmd(stack_t **head, char *line_tok, unsigned int line_number)
{
	int idx;
	instruction_t arr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div},
		{NULL, NULL}
	};

	idx = 0;
	while (arr[idx].opcode)
	{
		if (strcmp(arr[idx].opcode, line_tok) == 0)
		{
			arr[idx].f(head, line_number);
			return;
		}
		idx++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, line_tok);
	exit(EXIT_FAILURE);
}
