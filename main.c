#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * main - That show in interactive shell
 * @av - is a NULL terminated array of strings
 * @ac - is the number of items in av
 * Return: 0 on sucess
 */

int main(int ac, char **av)
{
	char *prompt = "shell $";
	char *lineptr;
	int nbytes = 100;
	size_t n = 0;

	(void) ac; 
	(void) av;

	printf("%s", prompt);
	lineptr = (char *) malloc (nbytes + 1);
	getline(&lineptr, &n, stdin);
	printf("%s\n", lineptr);

	free(lineptr);
	return (0);
}
