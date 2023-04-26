#include "shell.h"

/**
 * _path - path to execute the commands
 * @environ: the environ variable
 * Return: returns token
 */

char **_path(char **environ)
{
	int locate = 0;
	char **token;

	for (; environ[locate] != NULL ; locate++)
	{
		if (environ[locate][0] == 'p' && environ[locate][2] == 'T')
		{
			token = &(environ[locate]);
		}
	}
	return (token);
}
