#include "main.h"

/**
 * execute_line - finds in the shell buitins and commands
 *
 * @data: It is the argument
 * Return: 1 on success
 */

int execute_line(datash *data)
{
	int (*builtin)(datash *data);

	if (data->args[0] == NULL)
		return (1);

	builtin = get_builtins(data->args[0]);

	if (builtin != NULL)
		return (builtin(data));

	return (command_exec(data));
}
