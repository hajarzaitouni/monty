#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 *
 * @stack: a double pointer to the top of stack
 * @line_number: the line number of monty file
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int add = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	add = (*stack)-> + temp->n;
	temp-> = add;
	_pop(stack, line_number);
}
