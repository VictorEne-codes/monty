#include "monty.h"
/**
 * push - entry point inserts a new value in list
 * @node_stack: doubly linked list
 * @l_num: input
 */
void push(stack_t **node_stack, unsigned int l_num)
{
	stack_t *tmp = NULL, *tm = *node_stack;
	char *num;

	num = strtok(NULL, " \r\t\n");
	if (num == NULL || (_isdigit(num) != 0 && num[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", l_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp->n = atoi(num);
	if (var.MODE == 0 || !*node_stack)
	{
		tmp->next = *node_stack;
		tmp->prev = NULL;
		if (*node_stack)
			(*node_stack)->prev = tmp;
		*node_stack = tmp;
	}
	else
	{
		while (tm->next)
			tm = tm->next;
		tm->next = tmp;
		tmp->prev = tm;
		tmp->next = NULL;
	}
}
