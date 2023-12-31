#include "main.h"

/**
 * get_HELP - function that retrieves help messages
 * @data: data
 * Return: 0
 */

int get_HELP(datash *data)
{
	if (data->args[1] == 0)
		general_help();
	else if (_strcmp(data->args[1], "setenv") == 0)
		setenv_help();
	else if (_strcmp(data->args[1], "env") == 0)
		env_help();
	else if (_strcmp(data->args[1], "unsetenv") == 0)
		unsetenv_help();
	else if (_strcmp(data->args[1], "help") == 0)
		help_help();
	else if (_strcmp(data->args[1], "exit") == 0)
		exit_help();
	else if (_strcmp(data->args[1], "cd") == 0)
		cd_help();
	else if (_strcmp(data->args[1], "alias") == 0)
		help_alias();
	else
		write(STDERR_FILENO, data->args[0],
				_strlen(data->args[0]));

	data->stat = 0;
	return (1);
}


