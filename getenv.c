#include "shell.h"
/**
 * _getenv - Retrieves the value of an environment variable.
 * @env_var: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(const char *env_var)
{
	int i = 0;
	char *key, *value, *env_copy;

	while (environ[i])
	{
		env_copy = strdup(environ[i]);
		key = strtok(env_copy, "=");
		if (strcmp(env_var, key) == 0)
		{
			value = strdup(strtok(NULL, "\n"));
			free(env_copy);
			return (value);
		}
		i++;
		free(env_copy);
	}
	return (NULL);
}
