#include "main.h"

/**
 * getInput - gets input from standard in
 * @nchar: Length of the input
 * Return: Always returns string gotten
 */

char *getInput(ssize_t *nchar)
{
	char *line = NULL;
	size_t size = 0;

	*nchar = getline(&line, &size, stdin);
	if (*nchar  == -1)
	{
		write(2, "\n", 1);
		_free(line);
		exit(EXIT_FAILURE);
	}
	else
		return (line);
}

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
/**	_free(lineCopy); **/
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
			perror("./shell");
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

/**
 * print_message - Prints a message to standard output
 * @message: The message to be printed
 */
void print_message(const char *message)
{
	int i = 0;

	while (message[i] != '\0')
	{
		i++;
	}
	write(1, message, i);
}
