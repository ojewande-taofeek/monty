#include "monty.h"
/**
 * main - The programme for MONTY interpreter
 * @argc: The number of arguments passed in the command line
 * @argv: The vector to the array of arguments
 * Return: EXIT_SUCCESS, if successful
 *         Otherwise, EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	ssize_t fd, read_b, i, j, read_left;
	unsigned int line = 0;
	char *file_name, buffer[MAX_LENGTH], *buf_cpy, *cmd;
	stack_t *top = NULL;

	fd = intial_check(argc, argv);
	file_name = argv[1];
	read_b = read(fd, buffer, MAX_LENGTH);
	if (read_b == -1)
	{
		fprintf(stderr, "Error: Can't read file %s\n", file_name);
		return (EXIT_FAILURE);
	}
	for (i = 0, j = 0; i < read_b; i++, j++)
	{
		if (buffer[i] == '\n')
		{
			buf_cpy = malloc((i + 1) * sizeof(char));
			if (buf_cpy == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				return (EXIT_FAILURE);
			}
			strncpy(buf_cpy, buffer, j);
			buf_cpy[j] = '\0';
			line++;
			cmd = strtok(buf_cpy, " \t");
			if (cmd)
				cmd_caller(cmd, line, &top);
			free(buf_cpy);
			read_left = read_b - (i + 1);
			read_b = read_left;
			memmove(buffer, buffer + i + 1, read_b);
			i = -1;
			j = -1;
		}
	}
	free_all(&top);
	close(fd);
	return (EXIT_SUCCESS);
}
