#include "main.h"

/**
 * free_data - frees data structure
 * @data: data
 * Return: no return
 */

void free_data(datash *data)
{
	unsigned int item;

	for (item = 0; data->_environ[item]; item++)
	{
		free(data->_environ[item]);
	}

	free(data->_environ);
	free(data->pid);
}

/**
 * init_data - Initialize data
 * @data: data
 * @av: argument
 * Return: no return
 */

void init_data(datash *data, char **av)
{
	unsigned int item;

	data->av = av;
	data->input = NULL;
	data->args = NULL;
	data-> stat = 0;
	data->count = 1;

	for (item = 0; environ[item]; item++)
		;

	data->_environ = malloc(sizeof(char *) * (item + 1));

	for (item = 0; environ[item]; item++)
	{
		data->_environ[item] = _strdup(environ[item]);
	}

	data->_environ[item] = NULL;
	data->pid = itoa(getpid());
}

/**
 * main - That show in interactive shell
 * @av - is a NULL terminated array of strings
 * @ac - is the number of items in av
 * Return: 0 on sucess
 */

int main(int ac, char **av)
{
	datash data;
	(void) ac;

	signal(SIGINT, get_signal);
	init_data(&data, av);
	loop_sh(&data);
	free_data(&data);
	if (data.stat < 0)
		return (255);
	return (data.stat);
}
