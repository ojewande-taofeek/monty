#include "monty.h"
/**
 * main - the main programme
 * @argc: The command line counter
 * @argv: The command line vector
 * Return: 0, if successful
 *         Error message, if otherwise
 */

int main(int argc, char *argv[])
{
	FILE *fd;
	stack_t *head = NULL;
	char *filename, line[1024], *line_tok, *delm = " \n\v\b\t\r";
	unsigned int line_number = 0;

	head = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];

	fd = fopen(filename, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), fd))
	{
		line_tok = strtok(line, delm);
		line_number++;
		if (line_tok != NULL)
			cmd(&head, line_tok, line_number);
	}
	free_stack(&head);
	fclose(fd);
	return (0);
}
