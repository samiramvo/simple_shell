#include "main.h"

/**
 * cd_shell - changes current directory
 * @data: data
 * Return: 1 on success
 */

int cd_shell(datash *data)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = data->args[1];

	if (dir != NULL)
	{
		ishome = _strcmp("$HOME", dir);
		ishome2 = _strcmp("~", dir);
		isddash = _strcmp("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(data);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd_previous(data);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(data);
		return (1);
	}

	cd_to(data);

	return (1);
}

