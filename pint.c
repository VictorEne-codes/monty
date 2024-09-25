#include "monty.h"
/**
 * pint - entry point prints last node
 * @node_stack: Doubly linked list
 * @l_num: input
 */
void pint(stack_t **node_stack, unsigned int l_num)
{
	if (!*node_stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", l_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*node_stack)->n);
}
