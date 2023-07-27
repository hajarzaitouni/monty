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

/**
 * _mod - calcultes the remainder of division
 *
 * @stack: a double pointer to the top of stack
 * @line_number: the line number in monty file
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	int remainder;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_dlist(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n  == 0)
	{
		fprintf(stderr, "L%u, division by zero\n", line_number);
		free_dllist(*stack);
		exit(EXIT_FAILURE);
	}

	remainder = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = remainder;

	_pop(stack, line_number);
}
