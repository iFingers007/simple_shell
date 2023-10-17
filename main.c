#include "main.h"

char *lineptr = NULL;
char **cmd = NULL;

/**
 * cleanup - Cleansup the code
 *
 * Return: Void
 */
void cleanup(void)
{
	if (lineptr)
	{
		_free(lineptr);
		lineptr = NULL;
	}
	if (cmd)
	{
		free_cmds(cmd);
		cmd = NULL;
	}
}

/**
 * sigintHandler - Handles the signal input
 * @signum: The signal message number
 *Return: Void
*/

void sigintHandler(int signum)
{
	(void)signum;
	cleanup();
	exit(0);
}

/**
 * getInput - gets input from standard in
 * Return: Always returns string gotten
 */

char *getInput(void)
{
	ssize_t nchar;
	size_t size = 0;

	nchar = getline(&lineptr, &size, stdin);
	if (nchar  == -1)
	{
		write(2, "\n", 1);
		_free(lineptr);
		exit(EXIT_FAILURE);
	}
	lineptr[nchar - 1] = '\0';
	return (lineptr);
}

/**
 * main - entry point of a program
 *
 * Return: Always 0
 */
int main(void)
{
	char *prompt = "JehoAllen$ ";
	int inter;

	signal(SIGINT, sigintHandler);

	while (1)
	{
		inter = isatty(STDIN_FILENO);
		if (inter != 0)
			write(STDIN_FILENO, prompt, _strlen(prompt));
		lineptr = getInput();
		if (_strncmp(lineptr, "\n", _strlen(lineptr)) == 0)
		{
			_free(lineptr);
			continue;
		}
		if (!lineptr)
			chck(lineptr, "lineptr");
		cmd = processToken(lineptr);
		if (!cmd)
		{
			_free(lineptr);
			free_cmds(cmd);
			return (1);
		}
		create_process(cmd, lineptr);
		if (inter == 0)
			break;
		_free(lineptr);
		lineptr = NULL;
		free_cmds(cmd);
	}
	cleanup();
	return (0);
}
