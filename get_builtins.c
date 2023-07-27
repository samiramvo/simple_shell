#include "main.h"

/**
 * get_builtins - builtin (command in the args)
 * @command: command
 * Return: function pointer
 */

int (*get_builtins(char *command))(datash *)
{
	int i;
	builtin_t builtin[] = {
		{"env", _printenv },
		{"exit", exit_sh},
		{"setenv", _setenv },
		{"unsetenv", _unsetenv},
		{"cd", cd_shell},
		{"help", get_HELP},
		{NULL, NULL}
	};
	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, command) == 0)
			break;
	}
	return (builtin[i].f);
}
