#include "shell.h"

/**
 * _path - path to execute the commands
 * @environ: the environ variable
 * Return: returns token
 */

char **_path(char **environ)
{
	int location = 0;
	char **token;

	for (; environ[location] != NULL ; location++)
	{
		if (environ[location][0] == 'P && environ[location][2] == 'T')
		{
			token = &(environ[location]);
		}
	}
	return (token);
}
