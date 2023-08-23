#include "monty.h"
/**
 * check_malloc - The function checks if memory is allocated
 * Return: Nothing
 */
void check_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
