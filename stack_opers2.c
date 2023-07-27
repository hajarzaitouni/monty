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

/**
 *  _sub - subtracts the top element from the second top element of the stack
 *
 *  @stack: a double pointer to the to of the stack
 *  @line_number: the line number is monty file
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_dllist(*stack);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;

	_pop(stack, line_number);
}

/**
 * _div - divides the second top element of the stack by the top element
 *
 * @stack: a double pointer to the top of the stack
 * @line_number: the line number in monty file
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_dllist(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_dllist(*stack);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = result;
	_pop(stack, line_number);
}
