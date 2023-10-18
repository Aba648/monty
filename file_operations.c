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
		err(2, path_name);

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
	int line_num, format = 0;
	char *buffer = NULL;
	size_t length= 0;

	for (line_num = 1; getline(&buffer, &length, fd) != -1; line_num++)
	{
		format = tokenize_line(buffer, line_num, format);
	}
	free(buffer);
}
/**
 * tokenize_line - Separates each line into tokens to determine
 * @buffer: line from the file
 * @line_num: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * Return: Returns 0 or 1.
 */
int tokenize_line(char *buffer, int line_num, int format)
{
	char *opcode;
	char *val;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	
	_execute(opcode, val, line_num, format);
	return (format);
}

