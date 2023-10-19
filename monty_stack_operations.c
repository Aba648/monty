#include "monty.h"
/**
 * do_nothing - placeholder opcode in the Monty
 * @stack: Pointer
 * @line_number: the line number of of the opcode.
 */
void do_nothing(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * interchange_top - opcode in the Monty language that
 * interchanges the positions
 * @stack: Pointer
 * @line_number:  the line number of of the opcode.
 */
void interchange_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		handles_error(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_top_2 - adds the top two elements of the stack.
 * @stack: Pointer 
 * @line_number : the line number of of the opcode.
 */
void add_top_2(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * subtract_top_2 - Subtracts the top two elements of the stack.
 * @stack: Pointer
 * @line_number: the line number of of the opcode.
 */
void subtract_top_2(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_err(8, line_number, "sub");
	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * divise_top_2 - devise the top two elements of the stack.
 * @stack: Pointer
 * @line_number: the line number of of the opcode.
 */
void divise_top_2(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_err(8, line_number, "div");
	if ((*stack)->n == 0)
		_err(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
