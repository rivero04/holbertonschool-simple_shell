#include "shell.h"
/**
 * split_string - Splits a string into an array of tokens.
 * @buffer: The string to be split.
 * @del: The delimiter used to split the string.
 *
 * Return: An array of tokens, or NULL on failure.
 */
char **split_string(char *buffer, char *del)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 32);

	if (!tokens)
		return (NULL);

	token = strtok(buffer, del);
	while (token)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, del);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
