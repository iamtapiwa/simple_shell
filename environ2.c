#include "shell.h"

char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);

/**
 * _copyenv - Creates a copy of the environment.
 *
 * Return: If an error occurs - NULL.
 *         O/w - a double pointer to the new copy.
 */
char **_copyenv(void)
{
	char **new_env;
	size_t size;
	int i;

	for (size = 0; env[size]; size++)
		;

	new_env = malloc(sizeof(char *) * (size + 1));
	if (!new_env)
		return (NULL);

	for (i = 0; env[i]; i++)
	{
		new_env[i] = malloc(_strlen(env[i]) + 1);

		if (!new_env[i])
		{
			for (i--; i >= 0; i--)
				free(new_env[i]);
			free(new_env);
			return (NULL);
		}
		_strcpy(new_env[i], env[i]);
	}
	new_env[i] = NULL;

	return (new_env);
}

/**
 * free_env - Frees the the environment copy.
 */
void free_env(void)
{
	int i;

	for (i = 0; env[i]; i++)
		free(env[i]);
	free(env);
}

/**
 * _getenv - Gets an environmental variable from the PATH.
 * @var: The name of the environmental variable to get.
 *
 * Return: If the environmental variable does not exist - NULL.
 *         Otherwise - a pointer to the environmental variable.
 */
char **_getenv(const char *var)
{
	int i, len;

	len = _strlen(var);
	for (i = 0; env[i]; i++)
	{
		if (_strncmp(var, env[i], len) == 0)
			return (&env[i]);
	}

	return (NULL);
}
