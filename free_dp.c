#include "shell.h"

/**
 * free_dp - free file
 * @line: double pointer
 * Return: null
 */
char **free_dp(char **line)
{
	int i;

	if (line == NULL)
		return (NULL);

	for (i = 0; line[i]; i++)
	{
		free(line[i]);
		line[i] = NULL;
	}
	free(line);
	line = NULL;
	return (NULL);
}
