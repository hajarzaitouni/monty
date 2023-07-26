#include "monty.h"

/**
 * main - Entry point
 *
 * Description: create an interpreter for Monty files
 * @ac: number of arguments
 * @av: a pointer to array
 * Return: 0 (Success)
 */

int main(int ac, char *av[])
{
	FILE *fd;
	char *m_file = av[1];

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(m_file, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}

	execute(fd);

	return (0);
}
