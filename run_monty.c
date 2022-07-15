#include "monty.h"
#include <string.h>

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
