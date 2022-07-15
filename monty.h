#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.>
#include <unistd.h>

#define DELIMITER " \t\a\n\b"
#define STACK 0
#define QUEUE 1

extern void free_tokens(void);
extern unsigned int token_arr_len(void);
extern int check_empty_line(char *line, char *delims);
extern void (*get_op_func(char *opcode))(stack_t**, unsigned int);
extern int run_monty(FILE *file_d);


extern char **opcode_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


#endif
