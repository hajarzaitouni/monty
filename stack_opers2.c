#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 *
 * @stack: a double pointer to the top of stack
 * @line_number: the line number in monty file
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_dllist(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

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
		free_dllist(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	add = (*stack)->n + temp->n;
	temp->n = add;
	_pop(stack, line_number);
}

/**
 * _nop - doesn’t do anything
 *
 * @stack: a double pointer to the top of the stack
 * @line_number: the line number in monty file
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
