#include "monty.h"

void top_bottom(stack_t **stack, unsigned int line_num);
void bottom_top(stack_t **stack, unsigned int line_num);
void monty_que_stack(stack_t **stack, unsigned int line_num);
void monty_satck_que(stack_t **stack, unsigned int line_num);

/**
 * top_bottom - changes the top value of a stack_t linked_listto bottom
 * @stack: poiter to the top node of a stack linked_list
 * @line_num: the current working line number of a monty bytecode
 */

void top_bottom(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_num;
}

/**
 * bottom_top - changes the bottom value of a linked list to top
 * @stack: pointer to the top node
 * @line_num: current working line number of a monty bytecode
 */

void bottom_top(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_num;
}

/**
 * monty_que_stack - converts a queue to a stack
 * @stack: pointer to the top node of a stack linked list
 * @line_num: the current working line number of a monty bytecode
 */

void monty_que_stack(stack_t **stack, unsigned int line_num)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_stack_que - converts a stack to a queue
 * @stack: pointer to the top node of a stack linked list
 * @line_num: the current working line number of a monty bytecode
 */

void monty_stack_que(stack_t **stack, unsigned int line_num)
{
        (*stack)->n = QUEUE;
        (void)line_number;
}
