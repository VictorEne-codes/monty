#include "monty.h"

/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack
 * @node_stack: input
 * @l_num: input
 *
 * Return: void
 */

void sub(stack_t **node_stack, unsigned int l_num)
{
	if (!*node_stack || !(*node_stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			l_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*node_stack)->next->n = (*node_stack)->next->n - (*node_stack)->n;
	pop(node_stack, l_num);
}
