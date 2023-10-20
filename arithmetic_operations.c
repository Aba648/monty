#include "monty.h"
/**
 * multiply_top_2 -  multiplies the top two elements.
 * @stack: Pointer
 * @line_number: the line number of of the opcode.
 */
void multiply_top_2(stack_t **stack, unsigned int line_number)
{
	int resu;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	resu = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = resu;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * calc_modulo - Calculates the modulo.
 * @stack: Pointer
 * @line_number: the line number of of the opcode.
 */
void calc_modulo(stack_t **stack, unsigned int line_number)
{
	int resu;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_err(8, line_number, "mod");
	if ((*stack)->n == 0)
		_err(9, line_number);
	(*stack) = (*stack)->next;
	resu = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = resu;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
