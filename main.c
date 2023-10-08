#include "main.h"

/**
 * main - entry point of a program
 *
 * Return: Always 0
 */
int main(void)
{
	char *prompt = "JehoAllen$ ", *line = NULL;
	int inter;
	char **cmd = NULL;
	ssize_t charRead = 0;

	while (1)
	{
		inter = isatty(STDIN_FILENO);
		if (inter != 0)
			write(STDIN_FILENO, prompt, _strlen(prompt));
		line = getInput(&charRead);
		if (_strncmp(line, "\n", _strlen(line)) == 0)
		{
			free(line);
			continue;
		}
		cmd = processToken(line);

		create_process(cmd, line);
		if (inter == 0)
			break;
		_free(line);
		free_cmds(cmd);
	}

	return (0);
}
