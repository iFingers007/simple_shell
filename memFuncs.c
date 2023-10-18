#include "main.h"

/**
 * free_cmds - frees allocated memories
 *@cm: Arguments passed
 *
 *Return: Void
 */

void free_cmds(char **cm)
{
	int i = 0;

	if (cm == NULL)
		return;
	for (i = 0; cm[i]; i++)
	{
		if (cm[i] != NULL)
		{
			_free(cm[i]);
			cm[i] = NULL;
		}
	}
	free(cm);
}

/**
 * _free - Free allocated memory.
 * @cm: Argument passed
 *
 * Return: Void
 */

void _free(char *cm)
{
	if (cm == NULL)
		return;
	free(cm);
	cm = NULL;
}

/**
 * chckDmalloc - Checks for double malloc errors
 * @cm: Argument passed
 * @pCmd: Parent malloc
 *
 * Return: Null or pointer to address
 */

char *chckDmalloc(char *cm, char **pCmd)
{
	if (cm == NULL)
	{
		perror("malloc:");
		free(pCmd);
		return (NULL);
	}
	return (cm);
}

/**
 * chckSmalloc - Checks for single malloc errors
 *@cm: Argument passed
 *
 *Return: Null or pointer address
 */

char *chckSmalloc(char *cm)
{
	if (cm == NULL)
	{
		perror("malloc:");
		return (NULL);
	}
	return (cm);
}

/**
 * chck - Checks for single malloc errors
 *@lineptr: Argument passed
 *@msg: Error message
 *
 *Return: Void
 */

void chck(char *lineptr, char *msg)
{
	_free(lineptr);
	perror(msg);
	exit(EXIT_FAILURE);
}
