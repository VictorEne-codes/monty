#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>

#define Buffsize 30

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct glob_var
{
	FILE *file;
	char *buff;
	size_t tmp;
	instruction_t *dict;
	stack_t *head;
	unsigned int line_number;
	int MODE;
} vars;

extern vars var;


void swap(stack_t **node_stack, unsigned int l_num);
void add(stack_t **node_stack, unsigned int l_num);
void sub(stack_t **node_stack, unsigned int l_num);
int start_vars(vars *var);
void free_all(void);
instruction_t *create_instru();
int call_funct(vars *var, char *c);
int _isdigit(char *str);
void pall(stack_t **node_stack, unsigned int l_num);
void pint(stack_t **node_stack, unsigned int l_num);
void push(stack_t **node_stack, unsigned int l_num);
void pop(stack_t **node_stack, unsigned int l_num);
#endif
