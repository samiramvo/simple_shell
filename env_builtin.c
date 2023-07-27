#include "main.h"

/**
 * copy_inf - copies info to create
 * a new env or alias
 * @name: name
 * @val: value
 *
 * Return: new env
 */

char *copy_inf(char *name, char *val)
{
	char *newchar;
	int lenname, lenval, len;

	lenname = _strlen(name);
	lenval = _strlen(val);
	len = lenname + lenval + 2;
	newchar = malloc(sizeof(char) * (len));
	_strcpy(newchar, name);
	_strcat(newchar, "=");
	_strcat(newchar, val);
	_strcat(newchar, "\0");

	return (newchar);
}

/**
 * set_env - set envirronment variable
 *
 * @name : name of the environment variable
 * @value: value of the environment variable
 * @data: data
 * Return: No return
 */

void set_env(char *name, char *value, datash *data)
{
	int item;
	char *variable_env, *name_env;

	for (item = 0; data->_environ[item]; item++)
	{
		variable_env = _strdup(data->_environ[item]);
		name_env = _strtok(variable_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(data->_environ[item]);
			data->_environ[item] = copy_inf(name_env, value);
			free(variable_env);
			return;
		}
		free(variable_env);
	}

	data->_environ = _reallocdp(data->_environ, item, sizeof(char *) * (item + 2));
	data->_environ[item] = copy_inf(name, value);
	data->_environ[item + 1] = NULL;
}

/**
 * _setenv - compares env names
 * @data: data
 *
 * Return: 1 on success
 */

int _setenv(datash *data)
{
	if (data->args[1] == NULL || data->args[2] == NULL)
	{
		get_error(data, -1);
		return (1);
	}

	set_env(data->args[1], data->args[2], data);

	return (1);
}

/**
 * _unsetenv - deletes a environment
 * @data: data
 * Return: 1 on sucess
 */

int _unsetenv(datash *data)
{
	char **realloc_env;
	char *variable_env, *name_env;
	int item, item1, item2;

	if (data->args[1] == NULL)
	{
		get_error(data, -1);
		return (1);
	}
	item2 = -1;

	for (item = 0; data->_environ[item]; item++)
	{
		variable_env = _strdup(data->_environ[item]);
		name_env = _strtok(variable_env, "=");
		if (_strcmp(name_env, data->args[1]) == 0)
		{
			item2 = item;
		}
		free(variable_env);
	}
	if (item2 == -1)
	{
		get_error(data, -1);
		return (1);
	}
	realloc_env = malloc(sizeof(char *) * (item));
	for (item = item1 = 0; data->_environ[item]; item++)
	{
		if (item != item2)
		{
			realloc_env[item1] = data->_environ[item];
			item1++;
		}
	}
	realloc_env[item1] = NULL;
	free(data->_environ[item2]);
	free(data->_environ);
	data->_environ = realloc_env;
	return (1);
}

