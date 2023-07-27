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
		free_dllist(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n  == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_dllist(*stack);
		exit(EXIT_FAILURE);
	}

	remainder = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = remainder;

	_pop(stack, line_number);
}

/**
 * _pchar - prints the char at the top of the stack
 *
 * @stack: a double pointer to the top of the stack
 * @line_number: the line number in monty file
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_dllist(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * _pstr - prints the string starting at the top of the stack
 *
 * @stack: a double pointer to the stack
 * @line_number: the line number in monty file
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;

	while (temp)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
