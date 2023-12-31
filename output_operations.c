#include "monty.h"
/**
 * print_ch_ascii -  Prints the ASCII characted
 * @stack: Pointer
 * @line_number: the line number of of the opcode.
 */
void print_ch_ascii(stack_t **stack, unsigned int line_number)
{
	int ch_ascii;

	if (stack == NULL || *stack == NULL)
		char_err(11, line_number);

	ch_ascii = (*stack)->n;
	if (ch_ascii < 0 || ch_ascii > 127)
		char_err(10, line_number);
	printf("%c\n", ch_ascii);
}
/**
 * print_ascii_string - Prints a string of ASCII characters
 * @stack: Pointer
 * @ln: the line number of of the opcode.
 */
void print_ascii_string(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ch_ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ch_ascii = tmp->n;
		if (ch_ascii <= 0 || ch_ascii > 127)
			break;
		printf("%c", ch_ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rot_stack_left - Rotates the stack by moving
 * @stack: Pointer
 * @ln: the line number of of the opcode.
 */
void rot_stack_left(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rot_stack_right - Rotates the stack
 * @stack: Pointer
 * @ln: the line number of of the opcode.
 */
void rot_stack_right(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
