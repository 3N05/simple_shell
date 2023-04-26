#include "shell.h"

/**
 * _exit_function - to print
 * @void: exit
 * Return: none
 */
void _exit_function(void)
{
	kill(getpid(), SIGTERM);
}
