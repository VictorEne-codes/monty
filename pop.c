#include "monty.h"
/**
* pop - entry point removes top of list
* @node_stack: Doubly linked list
* @l_num: input
*/
void pop(stack_t **node_stack, unsigned int l_num)
{
	stack_t *tmp;

	if (!*node_stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", l_num);
		free_all();
		exit(EXIT_FAILURE);
	}

	tmp = *node_stack;
	*node_stack = tmp->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	free(tmp);
}
