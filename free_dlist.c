#include "monty.h"

/**
 * free_dllist - free the doubly likned list
 *
 * @stack: the tof of the stack
 */

void free_dllist(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
