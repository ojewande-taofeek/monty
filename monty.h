#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX_LENGTH 1024


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, char **buf_array);
} instruction_t;

char *_strdup(char *str);

extern stack_t *top;

int intial_check(int argc, char **argv);
void parser(char *buf_cpy, size_t line, stack_t **top);

void pall(stack_t **stack, char **buf_array);
void cmd_cmp(char **buf_array, size_t line, size_t count, stack_t **top);

void (*cmd_caller(char **, size_t count, size_t))(stack_t **, char **);
void check_malloc(void);

void push(stack_t **stack, char **buf_array);
stack_t *create_node(int n);
#endif /* MONTY_H */
