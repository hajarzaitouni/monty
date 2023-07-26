#include "monty.h"

/**
 * _push - push a node to the top of the stack
 *
 * @stack: a double pointer to the top of stack
 * @line_number: the line number in monty file
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int n;
	char *arg_token = strtok(NULL, " \n\t");

	if (arg_token == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg_token);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(*stack);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * _pall - prints all the elements of the stack
 *
 * @stack: a double pointer to the top of stack
 * @line_number: the line number in monty file
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * _pint - prints the value at the top of the stack
 *
 * @stack: a double pointer to the top of the stack
 * @line_number: the line number in monty file
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - removes the top element of the stack
 *
 * @stack: a double pointer to the top of the stack
 * @line_number: the line number in monty file
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	if (temp->next)
		temp->next->prev = NULL;
	free(temp);
}
