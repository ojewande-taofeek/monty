#include "monty.h"


/**
 * intial_check - The fucntion carry out preliminary checks
 * @argc: The number of arguments passed in the cmd line
 * @argv: The pointer to the arguments passed
 * Return: EXIT_SUCCESS, if successful
 *          EXIT_FAILURE, if otherwise
 */


ssize_t intial_check(int argc, char **argv)
{
	char *file_name;
	ssize_t fd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_name = argv[1];
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
