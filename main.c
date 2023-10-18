#include "monty.h"
stack_t *head = NULL;
/**
 * main - monty code interpreter
 * @argc: arguments count
 * @argv: list of arguments
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	op_file(argv[1]);
	bfree();
	return (0);
}

