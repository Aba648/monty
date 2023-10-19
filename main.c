#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @ac: arguments count
 * @av: list of arguments
 * Return: always 0
 */

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	op_file(av[1]);
	bfree();
	return (0);
}
