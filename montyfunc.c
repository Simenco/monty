#include "monty.h"

void monty_push(stack_t **stack, unsigned int line_num);
void monty_pall(stack_t **stack, unsigned int line_num);
void monty_pint(stack_t **stack, unsigned int line_num);
void monty_pop(stack_t **stack, unsigned int line_num);
void monty_swap(stack_t **stack, unsigned int line_num);

/**
 * monty_push - insert a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void monty_push(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (opcode_t[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_num));
		return;
	}

	for (i = 0; opcode_t[1][i]; i++)
	{
		if (opcode_t[1][i] == '-' && i == 0)
			continue;
		if (opcode_t[1][i] < '0' || opcode_t[1][i] > '9')
		{
			set_op_tok_error(no_int_error(line_num));
			return;
		}
	}
	new->n = atoi(opcode_t[1]);

	if (check_mode(*stack) == STACK) /* STACK mode insert at front */
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else /* QUEUE mode insert at end */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * monty_pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void monty_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * monty_pint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void monty_pint(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_num));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * monty_pop - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void monty_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_num));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * monty_swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void monty_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_num, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
