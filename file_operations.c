#include "monty.h"
/**
 * op_file - opens a file
 * @path_name: the file namepath
 * Return: void
 */

void op_file(char *path_name)
{
	FILE *fd = fopen(path_name, "r");

	if (path_name == NULL || fd == NULL)
		handles_error(2, path_name);

	read_from_file(fd);
	fclose(fd);
}
/**
 * read_from_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_from_file(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = tokenize_line(buffer, line_number, format);
	}
	free(buffer);
}
/**
 * tokenize_line - Separates each line into tokens to determine
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format.
 * Return: Returns 0 or 1.
 */
int tokenize_line(char *buffer, int line_number, int format)
{
	char *opcode;
	char *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		handles_error(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	_execute(opcode, value, line_number, format);
	return (format);
}

