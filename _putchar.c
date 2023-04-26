#include "shell.h"

/**
 * _putchar - writes the c character to standard output
 * @C: character to be printed
 * Return: returns 1 on success & -1 on fail or error
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
