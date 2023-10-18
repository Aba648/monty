#include "monty.h"
/**
 * _execute - executes the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void _execute(char *opcode, char *val, int line, int format)
{
	int j;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, j = 0; func_list[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, func_list[j].opcode) == 0)
		{
			_function(func_list[j].f, opcode, value, line, format);
			flag = 0;
		}
	}
	if (flag == 1)
		handles_error(3, line, opcode);
}
/**
 * _function - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @p: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 */
void _function(op_func func, char *p, char *val, int ln, int format)
{
	stack_t *n;
	int i;
	int flag;

	flag = 1;
	if (strcmp(p, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			handles_error(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				handles_error(5, ln);
		}
		n = _n(atoi(val) * flag);
		if (format == 0)
			func(&n, ln);
		if (format == 1)
			(&n, ln);
	}
	else
		func(&head, ln);
}
