#include "monty.h"

/**
 * execute - read from the file and execute the corresponding opcode
 *
 * @file_d: the file to read from
 */

void execute(FILE *file_d)
{
	char *lineptr = NULL;
	char *opc_token;
	unsigned int line_number = 1;
	size_t count = 0;
	ssize_t read;

	stack_t *stack = NULL;

	while ((read = getline(&lineptr, &count, file_d)) != -1)
	{
		opc_token = strtok(lineptr, " \n\t");
		if (opc_token == NULL || opc_token[0] == '#')
		{
			line_number++;
			continue;
		}

		get_opcode_func(&stack, line_number, opc_token);
		line_number++;
	}

	free_dllist(stack);
	free(lineptr);
	fclose(file_d);
}
