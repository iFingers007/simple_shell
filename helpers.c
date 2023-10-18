#include "main.h"

/**
 * processToken - Print each character of a token.
 * @line: The input line to be processed.
 * Return: Array of token string
*/

char **processToken(char *line)
{
	int i = 0;
	char *token = NULL, **cm = malloc(sizeof(char *) * CMD_SIZE);

	if (cm == NULL)
	{
		perror("malloc:");
		_free(line);
		return (NULL);
	}
	token = strtok(line, " \n");
	while (token != NULL)
	{
		cm[i] = malloc(sizeof(char) * _strlen(token) + 1);
		if (cm[i] == NULL)
		{
			perror("malloc:");
			free_cmds(cm);
			exit(EXIT_FAILURE);
		}

		_strcpy(cm[i], token);
		token = strtok(NULL, " \n");
		i++;
	}

	cm[i] = NULL;
	return (cm);
}

/**
 * create_process - this creates a child process to run
 * @line: The input line to be processed.
 * @cm: an array holding each command and passed arguments
 * Return: returns 0 for success and 1 for failure
 */
int create_process(char *cm[], char *line)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		_free(line);
		free_cmds(cm);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(cm[0], cm, environ) == -1)
		{
			perror("./shell");
			free(line);
			free_cmds(cm);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
