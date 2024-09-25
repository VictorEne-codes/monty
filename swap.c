#include <monty.h>

/*
 * swap - a function that sqaps the two top elenets in the stack
 * @node_stack: input
 * @l_num:  input
 *
 * Return: void
 */

void swap(stack_t **node_stack, unsigned int l_num)
{
	int tmp;

	if (!*node_stack || !(*node_stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			l_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = (*node_stack)->n;
	(*node_stack)->n = (*node_stack)->next->n;
	(*node_stack)->next->n = tmp;
}
