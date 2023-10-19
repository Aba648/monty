#include "monty.h"
/**
 * _node - crearts a node
 * @i: number to go inside the node.
 * Return: upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *_node(int i)
{
	stack_t *d;

	d = malloc(sizeof(stack_t));
	if (d == NULL)
		_err(4);
	d->next = NULL;
	d->prev = NULL;
	d->i = i;
	return (i);
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
