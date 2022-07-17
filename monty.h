#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.>
#include <unistd.h>

#define DELIMITER " \t\a\n\b"
#define STACK 0
#define QUEUE 1

extern char **opcode_t;

/*
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

extern void free_tokens(void);
extern unsigned int token_arr_len(void);
extern int check_empty_line(char *line, char *delims);
extern void (*get_op_func(char *opcode))(stack_t**, unsigned int);
extern int run_monty(FILE *file_d);
extern int usage_error(void);
extern int malloc_error(void);
extern int f_open_error(char *filename);
extern int unknown_op_error(char *opcode, unsigned int line_num);
extern int no_int_error(unsigned int line_num);
extern int short_stack_error(unsigned int line_num, char *op);
extern int div_error(unsigned int line_num);
extern int pop_error(unsigned int line_num);
extern int div_error(unsigned int line_num);
extern int pchar_error(unsigned int line_num, char *message)


extern void monty_push(stack_t **stack, unsigned int line_num);
extern void monty_pall(stack_t **stack, unsigned int line_num);
extern void monty_pint(stack_t **stack, unsigned int line_num);
extern void monty_pop(stack_t **stack, unsigned int line_num);
extern void monty_swap(stack_t **stack, unsigned int line_num);
extern void monty_add(stack_t **stack, unsigned int line_num);
extern void monty_sub(stack_t **stack, unsigned int line_num);
extern void monty_div(stack_t **stack, unsigned int line_num);
extern void monty_mul(stack_t **stack, unsigned int line_num);
extern void monty_mod(stack_t **stack, unsigned int line_num);
extern void monty_nop(stack_t **stack, unsigned int line_num);
extern void monty_pchar(stack_t **stack, unsigned int line_num);
extern void monty_pstr(stack_t **stack, unsigned int line_num);

void top_bottom(stack_t **stack, unsigned int line_num);
void bottom_top(stack_t **stack, unsigned int line_num);
void monty_que_stack(stack_t **stack, unsigned int line_num);
void monty_satck_que(stack_t **stack, unsigned int line_num);

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base, char *buff, int buff_size);

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

#endif
