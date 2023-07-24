#include "main.h"
/**
 * read_lines - when the inputs string is reads
 * @value: return a value of get_line function
 * Return: String
 */

char *read_lines(int *value)
{
	size_t bufsize = 0;
	char *inp = NULL;
	*value = getline(&inp, &bufsize, stdin);

	return (inp);
}
