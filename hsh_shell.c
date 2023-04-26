#include "shell.h"

/**
 * main - used for executing all main functions
 * @argc: counts the number of arguments
 * @av: pointer to arguments
 * @env: location
 * Return: returns nothing
 */

int main(int argc __attribute__((unused)), char **av, char **env)
{
	char *string = NULL, **line = NULL;
	int _num_prompt = 0, val_isatty = 0;

	while (1)
	{
		val_isatty = isatty(STDIN_FILENO);
		string = get_line(val_isatty);

		if (_strcmp(string, "exit\n") == 0)
		{
			free(string);
			exit(0);
		}
		if (string != NULL)
		{
			_num_prompt++;
			line = strtok(String);
			_execev(line, av[0], _num_prompt, val_isatty, env);
			free(string);
			free(line);
		}
		val isatty = 0;
	}
	return (0);
}
