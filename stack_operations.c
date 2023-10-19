#include "monty.h"
/**
 * _node - crearts a node
 * @n: number to go inside the node.
 * Return: upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		handles_error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
/**
 * f_queue - prints the top
 * @new_n: pointer to the new node.
 * @line: line_number.
 * Return: no return
 */
void f_queue(stack_t **new_n, unsigned int line)
{
	stack_t *tmp;
	(void)line;

	if (new_n == NULL || *new_n == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_n;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_n;
	(*new_n)->prev = tmp;

}
