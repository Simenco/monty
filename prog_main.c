#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **opcode_t = NULL;

/**
 * main - the main function for the Monty project
 * @argc: argument count
 * @argv: arrays of arguments
 * Return: EXIT_SUCCESS if successful and EXIT_FAILURE if not
 */

int main(int argc, char **argv[])
{
	FILE *file_d = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	file_d = fopen(argv[1], "r");
	if (file_d == NULL)
		return (f_open_error(argv[1]));
	exit_code = run_monty(file_d);
	fclose(file_d);
	return (exit_code);
}
