#include "main.h"

/**
 * exit_sh - exit the shell
 * @data: data relevant
 * Return: 0 on success
 */

int exit_sh(datash *data)
{
	int is_digit;
	int str_len;
	int bignumber;
	unsigned int ustatus;

	if (data->args[1] != NULL)
	{
		ustatus = _atoi(data->args[1]);
		is_digit = _isdigit(data->args[1]);
		str_len = _strlen(data->args[1]);
		bignumber = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || bignumber)
		{
			get_error(data, 2);
			data->stat = 2;
			return (1);
		}
		data->stat = (ustatus % 256);
	}
	return (0);
}



