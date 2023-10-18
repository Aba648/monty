#include "monty.h"
/**
 * bfree - Frees nodes in the stack.
 */
void bfree(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
