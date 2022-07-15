#include "monty.h"

int short_stack_error(unsigned int line_num, char *op);
int div_error(unsigned int line_num);
int pop_error(unsigned int line_num);
int div_error(unsigned int line_num);
int pchar_error(unsigned int line_num, char *message);

/**
 * pop_error - Prints pop error messages for empty stacks.
 * @line_num: Line number in script where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pop_error(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
	return (EXIT_FAILURE);
}

/**
 * pint_error - Prints pint error messages for empty stacks.
 * @line_num: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pint_error(unsigned int line_num)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - Prints monty math function error messages
 *                     for stacks/queues smaller than two nodes.
 * @line_num: Line number in Monty bytecodes file where error occurred.
 * @op: Operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int short_stack_error(unsigned int line_num, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_num, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - Prints division error messages for division by 0.
 * @line_num: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int div_error(unsigned int line_num)
{
	fprintf(stderr, "L%u: division by zero\n", line_num);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - Prints pchar error messages for empty stacks
 *               empty stacks and non-character values.
 * @line_num: Line number in Monty bytecodes file where error occurred.
 * @message: The corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pchar_error(unsigned int line_num, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_num, message);
	return (EXIT_FAILURE);
}
