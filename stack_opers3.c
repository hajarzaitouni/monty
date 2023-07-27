#include "monty.h"

/**
 * _mul - multiplies the second top element of the stack with the top element
 *
 * @stack: a double pointer to the top of stack
 * @line_number: the line number in monty file
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	int mult;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_dllist(*stack);
		exit(EXIT_FAILURE);
	}

	mult = ((*stack)->n) * ((*stack)->next->n);
	(*stack)->next->n = mult;

	_pop(stack, line_number);
}
