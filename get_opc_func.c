#include "monty.h"

/**
 * get_opcode_func - get the corresponding opcode
 *
 * @stack: a double pointer to the top of stack
 * @line_number: the line number in monty file
 * @opc: the opcode in the file
 */

void get_opcode_func(stack_t **stack, unsigned int line_number, char *opc)
{
	instruction_t operations[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{NULL, NULL}
	};

	int i = 0;

	while (operations[i].opcode != NULL)
	{
		if (strcmp(operations[i].opcode, opc) == 0)
		{
			operations[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opc);
	free_dllist(*stack);
	exit(EXIT_FAILURE);
}
