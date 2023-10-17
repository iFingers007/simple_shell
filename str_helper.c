#include "main.h"

/**
 * _strncmp - Compares first nbytes of two strings
 *@s1: First string
 *@s2: Second string
 *@n: Number of bytes to compare
 *Return: 0 if equal, Greater than 1 or less than 1
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return (-1);
	if (s2 == NULL)
		return (1);
	while (n--)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1) - (*(unsigned char *)s2);
		if (*s1 == '\0')
			return 0;

		s1++;
		s2++;
	}
	return 0;
}

/**
 * _strcpy - Copies a string
 *@sdest: Destination string
 *@src: Source string
 *Return: destination string or null
 */

char *_strcpy(char *dest, char *src)
{
	char *ptr;

	if (dest == NULL || src == NULL)
	{
		perror("strcpy:");
		return (NULL);
	}
	ptr = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (ptr);
}

/**
 * _strlen - this returns the length of the string
 * @str: the strin to return its length
 * Return: returns the length of the string str
 */
size_t _strlen(const char *str)
{
	size_t count = 0;

	if (str == NULL)
		return (0);
	while (str[count])
		count++;

	return (count);
}

/**
 * _strdup - Duplicates a string
 * @str: the string to return its length
 * Return: returns the copy of the string or NULL
 */
char *_strdup(char *str)
{
	size_t len = _strlen(str);
	char *copy;

	if (str == NULL)
		return (NULL);
	copy = malloc((len + 1) * sizeof(str));
	if (copy == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	_strcpy(copy, str);
	return (copy);
}
/**
 * _strcat - Concatenates a string
 *@sdest: Destination string
 *@src: Source string
 *Return: destination string or null
 */

char *_strcat(char *dest, char *src)
{
	char *p;
	if (dest == NULL || src == NULL)
	{
		perror("Invalid input");
		exit(EXIT_FAILURE);
	}
	p = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (p);
}
