#include "monty.h"

/**
 * start_vars - Fake rand to jackpoint Giga Millions
 * @var: input
 *
 * Return: int
 */

int start_vars(vars *var)
{
	var->file = NULL;
	var->buff = NULL;
	var->tmp = 0;
	var->dict = create_instru();
	if (var->dict == NULL)
		return (EXIT_FAILURE);
	var->head = NULL;
	var->line_number = 1;
	var->MODE = 0;

	return (EXIT_SUCCESS);
}

/**
 * create_instru - Create new functions dictionary
 * Return: instruction_t
 */

instruction_t *create_instru()
{
	instruction_t *p = malloc(sizeof(instruction_t) * 18);

	if (!p)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	p[0].opcode = "pall", p[0].f = pall;
	p[1].opcode = "push", p[1].f = push;
	p[2].opcode = "pint", p[2].f = pint;
	p[3].opcode = "pop", p[3].f = pop;
	p[4].opcode = "swap", p[4].f = swap;
	p[5].opcode = "add", p[5].f = add;
	p[6].opcode = "nop", p[6].f = NULL;
	p[7].opcode = "sub", p[7].f = sub;
	p[8].opcode = "div", p[8].f = divi;
	p[9].opcode = "mul", p[9].f = mul;
	p[10].opcode = "mod", p[10].f = mod;
	p[11].opcode = "pchar", p[11].f = pchar;
	p[12].opcode = "pstr", p[12].f = pstr;
	p[13].opcode = "rotl", p[13].f = rotl;
	p[14].opcode = "rotr", p[14].f = rotr;
	p[15].opcode = "stack", p[15].f = stack;
	p[16].opcode = "queue", p[16].f = queue;
	p[17].opcode = NULL, p[17].f = NULL;

	return (p);
}

/**
 * call_funct - Call Functions
 * @var: input
 * @c: input
 *
 * Return: int
 */

int call_funct(vars *var, char *c)
{
	int i;

	for (i = 0; var->dict[i].c; i++)
		if (strcmp(c, var->dict[i].c) == 0)
		{
			if (!var->dict[i].f)
				return (EXIT_SUCCESS);
			var->dict[i].f(&var->head, var->line_number);
			return (EXIT_SUCCESS);
		}
	if (strlen(c) != 0 && c[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			var->line_number, c);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}


/**
 * free_all - Clean all program mallocs
 * Return: void
 */

void free_all(void)
{
	if (var.buff != NULL)
		free(var.buff);
	if (var.file != NULL)
		fclose(var.file);
	free(var.dict);
	if (var.head != NULL)
	{
		while (var.head->next != NULL)
		{
			var.head = var.head->next;
			free(var.head->prev);
		}
		free(var.head);
	}
}

/**
 * _isdigit - Clean all program mallocs
 * @str: input
 *
 * Return: int
 */

int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
	}
	return (0);
}
