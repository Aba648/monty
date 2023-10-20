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
void _execute(char *opcode, char *value, int ln, int format)
{
	int j;
	int flag;

	instruction_t func_list[] = {
		{"push", add_2stack},
		{"pall", display_stack},
		{"pint", display_top_node},
		{"pop", discard_top},
		{"nop", do_nothing},
		{"swap", interchange_top},
		{"add", add_top_2},
		{"sub", subtract_top_2},
		{"div", divise_top_2},
		{"mul", multiply_top_2},
		{"mod", calc_modulo},
		{"pchar", print_ch_ascii},
		{"pstr", print_ascii_string},
		{"rotl", rot_stack_left},
		{"rotr", rot_stack_right},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, j = 0; func_list[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, func_list[j].opcode) == 0)
		{
			_function(func_list[j].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		handles_error(3, ln, opcode);
}
/**
 * _function - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @p: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 */
void _function(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int i;
	int flag;

	flag = 1;
	if (strcmp(op, "push") == 0)
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
		node = _node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			f_queue(&node, ln);
	}
	else
		func(&head, ln);
}
