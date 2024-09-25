#include <monty.h>

/*
 * add - a function to add the top two numbers of the stack
 * @node_stack: input
 * @l_num: input
 *
 * Return: void
 */

void add(stack_t **node_stack, unsigned int l_num)
{
	if (!*node_stack || !(*node_stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			l_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*node_stack)->next->n = (*node_stack)->next->n + (*node_stack)->n;
	pop(node_stack, l_num);
}
