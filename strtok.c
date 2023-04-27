#include "shell.h"

/**
 * _strtok - split to token of strok
 * @line_messages: recieved by user
 * Return: chit(s)
 */
char **_strtok(char *line_messages)
{
	char *delimiters = " ,!¡¿?'\"\n\t";
	char *chit = NULL, **array = NULL;
	int i = 0;

	if (line_messages == NULL)
	{
		return (NULL);
	}

	array = malloc((_strlen(line_messages) + 1024) * sizeof(char *));;

	chit = strtok(line_messages, delimiters);
	array[i] = chit;

	while (chit)
	{
		i++;
		chit = strtok(NULL, delimiters);
		array[i] = chit;
	}
	i++;
	array[i] = NULL;
	return (array);
}
