#include "shell.h"

char *_strchr(char *str, char c);
int _strspn(char *str, char *accept);
int _strcmp(char *str1, char *str2);
int _strncmp(const char *str1, const char *str2, size_t n);

/**
 * _strchr - Locates a character in a string.
 * @str: The string to be searched.
 * @c: The character to be located.
 *
 * Return: If c is found - a pointer to the first occurence.
 *         If c is not found - NULL.
 */
char *_strchr(char *str, char c)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == c)
			return (s + i);
	}

	return (NULL);
}

/**
 * _strspn - Gets the length of a prefix substring.
 * @str: The string to be searched.
 * @accept: The prefix to be measured.
 *
 * Return: The number of bytes in str which
 *         consist only of bytes from accept.
 */
int _strspn(char *str, char *accept)
{
	int bytes = 0;
	int i;

	while (*str)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*str == accept[i])
			{
				bytes++;
				break;
			}
		}
		str++;
	}
	return (bytes);
}

/**
 * _strcmp - Compares two strings.
 * @str1: The first string to be compared.
 * @str2: The second string to be compared.
 *
 * Return: Positive byte difference if str1 > str2
 *         0 if length of str1 = str2
 *         Negative byte difference if str1 < str2
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);

	return (0);
}

/**
 * _strncmp - Compare two strings.
 * @str1: Pointer to a string.
 * @str2: Pointer to a string.
 * @n: The first n bytes of the strings to compare.
 *
 * Return: Less than 0 if str1 is shorter than str2.
 *         0 if str1 and str2 match.
 *         Greater than 0 if str1 is longer than str2.
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; str1[i] && str2[i] && i < n; i++)
	{
		if (str1[i] > str2[i])
			return (str1[i] - str2[i]);
		else if (str1[i] < str2[i])
			return (str1[i] - str2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-15);
}
