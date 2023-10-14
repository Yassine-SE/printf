#include "main.h"

/**
 * _strlen - check the code
 * @s: param
 *
 * Return: Always 0.
 */
int _strlen(char *s)
{
	int i, count;

	count = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		count++;
	}
	return (count);
}
