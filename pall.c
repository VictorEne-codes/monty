#include "monty.h"

/**
 * pall - Print all element in list
 * @node_stack: input
 * @l_num: input
 *
 * Return: void
 */

void pall(stack_t **node_stack, unsigned int l_num)
{
	stack_t *tmp = *node_stack;
	(void) l_num;

	if (!tmp)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
