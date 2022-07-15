#include "monty.h"
#include <string.h>

void free_tokens(void);
unsigned int token_arr_len(void);
int check_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *file_d);

/**
 * free_tokens - frees the global opcode_t array
 */
void free_tokens(void)
{
	size_t i = 0;

	if (opcode_t == NULL)
		return;

	for (i = 0; opcode_t[i]; i++)
		free(opcode_t[i]);

	free(opcode_t);
}

/**
 * token_arr_len - Gets the length of current opcode_t
 *
 * Return: Length of current opcode_t
 */
unsigned int token_arr_len(void)
{
	unsigned int toks_len = 0;

	while (opcode_t[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * check_empty_line - checks if line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int check_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; opcode_func[i]->opcode; i++)
	{
		if (strcmp(opcode, opcode_func[i]->opcode) == 0)
			return (opcode_func[i]->f);
	}

	return (NULL);
}

/**
 * run_monty - this function runs a monty bytecode script
 * @file_d: file descriptor when Monty bytecode opens
 *
 * Return: EXIT_SUCCESS if successful and error code on failure
 */

int run_monty(FILE *file_d)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned line_num = 0, tok_len = 0;
	void (*opcode_func)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, file_d) != -1)
	{
		line_num++;
		opcode_t = strtow(line, DELIMITER);
		if (opcode_t == NULL)
		{
			if (check_empty_line(line, DELIMITER))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (opcode_t[0][0] == '#')
		{
			free_tokens();
			continue;
		}
		opcode_func = get_op_func(opcode_t[0]);
		if (opcode_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_op_error(opcode_t[0], line_num);
			free_tokens();
			break;
		}
		tok_len = token_arr_len();
		opcode_func(&stack, line_num);
		if (token_arr_len() != tok_len)
		{
			if (opcode_t && opcode_t[tok_len])
				exit_status = atoi(op_toks[tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}

	free(line);
	return (exit_status);
}
