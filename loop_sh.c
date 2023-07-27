#include "main.h"

/**
 * delete_com - delete comment in the input
 *
 * @in: input string
 * Return: input without comments
 */

char *delete_com(char *in)
{
	int i, update_to;

	update_to = 0;
	for (i = 0; in[i]; i++)
	{
		/* if input is # */
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}
			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				update_to = i;
		}
	}

	if (update_to != 0)
	{
		in = _realloc(in, i, update_to + 1);
		in[update_to] = '\0';
	}

	return (in);
}

/**
 * loop_sh - loop of shell
 * @data: data
 * Return: No return
 */

void loop_sh(datash *data)
{
	int lp, ieof;
	char *inp;

	lp = 1;
	while (lp == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		inp = read_lines(&ieof);
		if (ieof != -1)
		{
			inp = delete_com(inp);
			if (inp == NULL)
				continue;

			if (check_syntax_error(data, inp) == 1)
			{
				data->stat = 2;
				free(inp);
				continue;
			}
			inp = rep_var(inp, data);
			lp = split_commands(data, inp);
			data->count += 1;
			free(inp);
		}
		else
		{
			lp = 0;
			free(inp);
		}
	}
}
