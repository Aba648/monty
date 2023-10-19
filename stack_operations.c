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
		_err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
/**
 * f_queue - prints the top
 * @new_node: pointer to the new node.
 * @ln: line_number.
 * Return: no return
 */
void f_queue(stack_t **new_node, unsigned int ln)
{
	stack_t *tmp;
	(void)ln;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}
