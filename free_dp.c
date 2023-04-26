#include "shell.h"

/**
 * free_dp - free file
 * @line: double pointer
 * Return: null
 */
char **free_dp(char **line)
{
	int x;

	for (x = 0; line[x]; x++)
	{
		free(line[x]);
		line[x] = NULL;
	}
	free(line);
	line = NULL;
	return (NULL);
}
