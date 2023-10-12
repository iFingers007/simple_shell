#include "main.h"

/**
 * free_cmds - frees allocated memories
 *@cmd: Arguments passed
 *
 *Return: Void
 */

void free_cmds(char **cmd)
{
	int i = 0;

	if (cmd == NULL)
		return;
	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] != NULL)
			free(cmd[i]);
	}
	if (cmd != NULL)
		free(cmd);
}

/**
 * _free - Free allocated memory.
 * @cmd: Argument passed
 *
 * Return: Void
 */

void _free(char *cmd)
{
	if (cmd == NULL)
		return;
	free(cmd);
}

/**
 * chckDmalloc - Checks for double malloc errors
 * @cmd: Argument passed
 * @pCmd: Parent malloc
 *
 * Return: Null or pointer to address
 */

char *chckDmalloc(char *cmd, char **pCmd)
{
	if (cmd == NULL)
	{
		perror("malloc:");
		free(pCmd);
		return (NULL);
	}
	return (cmd);
}

/**
 * chckSmalloc - Checks for single malloc errors
 *@cmd: Argument passed
 *
 *Return: Null or pointer address
 */

char *chckSmalloc(char *cmd)
{
	if (cmd == NULL)
	{
		perror("malloc:");
		return (NULL);
	}
	return (cmd);
}
