#include "shell.h"

/**
 * _execev - executes a program exe
 * *@line: receives from strtok the token
 * @argv: arguments in file
 * @num: variables
 * @isatty_val: it is the tty
 * @env: enviroment variable
 * Return: nothing
 */

void _execev(char **line, char *argv, int num, int isatty_val, char **env)
{
pid_t pid;
int _exec = 0;

if (line[0] == NULL)
return;

if (is_buit(line, env) == 1)
return;

pid = fork();
if (pid < 0)
{
perror("Error during fork\n");
free_dp(line);
exit(EXIT_FAILURE);
}
else if (pid != 0)
{
wait(NULL);
return;
}
else
{
if (check_path(env, line) == 0)
_exec = execve(line[0], line, env);
if (_exec < 0)
{
if (isatty_val == 1)
{
printf("%s: No such file or directory\n", argv);
free(line);
exit(EXIT_SUCCESS);
}
printf("%s: %d: %s: not found\n", argv, num, line[0]);
free(line);
exit(EXIT_FAILURE);
}
free_dp(line);
exit(EXIT_SUCCESS);
}
}
