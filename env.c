#include "main.h"

/**
 * comp_env - variable names(compares)
 * @name_env: name of environment variable
 * @name: name
 * Return: 0 if they are not equal . another value if they are
 */

int comp_env(const char *name_env, const char *name)
{
	int item;

	for (item; name_env[item] != '='; item++)
	{
		if (name_env[item] != name[item])
		{
			return (0);
		}
	}
	return (item + 1);
}

/**
 * _getenv - get an environment var
 * @name: name of the environment variable
 * @_environ: environment variable
 * Return: Value of the environment variable
 */

char *_getenv(const char *name, char **_environ)
{
	char *env1;
	int item, comp;

	env1 = NULL;
	comp = 0;

	for (item = 0; _environ[item]; item++)
	{
		comp = comp_env(_environ[item], name);
		if (comp)
		{
			env1 = _environ[item];
		}
	}
	return (env1 + comp);
}

/**
 * _printenv - print the environment variable
 *
 * @data: data
 * Return: 1 on sucess
 */

int _printenv(datash *data)
{
	int item, item2;

	for (item = 0; data->_environ[item]; item++)
	{
		for (item2 = 0; data->_environ[item][item2]; item2++)
		{
			write(STDOUT_FILENO, data->_environ[item], item2);
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	data->stat = 0;
	return (1);
}
