#include "monty.h"

/**
 * handles_error - Prints appropiate error messages
 *					determined by their error code.
 * @error : The error code.
 */
void handles_error(int error, ...)
{
	va_list ag;
	char *op;
	int l;

	va_start(ag, error);
	switch (error)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	bfree();
	exit(EXIT_FAILURE);
}
 * @error : The error code.
 */
void _err(int error, ...)
{
	va_list ag;
	char *op;
	int l;

	va_start(ag, error);
	switch (error)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	bfree();
	exit(EXIT_FAILURE);
}
/**
 * string_err - handles errors.
 * @error: The error codes
 */
void string_err(int error, ...)
{
	va_list ag;
	int l;

	va_start(ag, error);
	l = va_arg(ag, int);
	switch (error)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l);
			break;
		default:
			break;
	}
	bfree();
	exit(EXIT_FAILURE);
}
