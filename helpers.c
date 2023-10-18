#include "main.h"

/**
 * processToken - Print each character of a token.
 * @line: The input line to be processed.
 * Return: Array of token string
*/

char **processToken(char *line)
{
	int i = 0;
	char *token = NULL, **cmd = malloc(sizeof(char *) * CMD_SIZE);

	if (cmd == NULL)
	{
		perror("malloc:");
		_free(line);
		return (NULL);
	}
	token = strtok(line, " \n");
	while (token != NULL)
	{
		cmd[i] = malloc(sizeof(char) * _strlen(token) + 1);
		if (cmd[i] == NULL)
		{
			perror("malloc:");
			free_cmds(cmd);
			exit(EXIT_FAILURE);
		}

		_strcpy(cmd[i], token);
		token = strtok(NULL, " \n");
		i++;
	}

	cmd[i] = NULL;
	return (cmd);
}

/**
 * create_process - this creates a child process to run
 * @line: The input line to be processed.
 * @cmd: an array holding each command and passed arguments
 * Return: returns 0 for success and 1 for failure
 */
int create_process(char *cmd[], char *line)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		_free(line);
		free_cmds(cmd);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			free(line);
			free_cmds(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
