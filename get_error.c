#include "main.h"

/**
 * get_error - calls the error according the builtin
 * @data: data
 * @error_val: error value
 * Return: error
 */

int get_error(datash *data, int error_val)
{
	char *err;

	switch (error_val)
	{
		case -1:
			err = error_env(data);
			break;
		case 126:
			err = error_path_126(data);
			break;
		case 127:
			err = error_not_found(data);
			break;
		case 2:
			if (_strcmp("exit", data->args[0]) == 0)
				err = error_exit_shell(data);
			else if (_strcmp("cd", data->args[0]) == 0)
				err = error_get_cd(data);
			break;
	}

	if (err)
	{
		write(STDERR_FILENO, err, _strlen(err));
		free(err);
	}
	data->stat = error_val;
	return (error_val);
}
