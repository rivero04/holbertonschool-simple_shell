#include "shell.h"

/**
 * main - Entry point of the program.
 * @ac: Number of arguments.
 * @av: Array of argument strings.
 * @env: Array of environment variable strings.
 * Return: 0
 */
int main(void)
{
    char **args, *buffer = NULL;
    size_t length, buffer_size = 0;
    int n_chars, status;

    while (1)
    {
        if (isatty(fileno(stdin))) 
        {
            write(1, PROMPT, strlen(PROMPT));
        }
        
        n_chars = getline(&buffer, &buffer_size, stdin);
        if (n_chars == -1)
            break;

        length = strlen(buffer);
        buffer[length - 1] = '\0';

        args = split_string(buffer, " \t\n");
        if (args[0])
        {
            if (!strcmp(args[0], "exit"))
            {
                free_tokens(args);
                free(buffer);
                return (0);
            }
            if (strcmp(args[0], "env") == 0 || strcmp(buffer, "env") == 0)
            {
                printenv();
                free_tokens(args);
                continue;
            }
            
            status = execute_command(args);
            status = executeWithPath(args[0], args);


            if (WIFEXITED(status) && WEXITSTATUS(status) == 2)
            {
                free_tokens(args);
                free(buffer);
                return (2);
            }
        }
        free_tokens(args);
    }
    free(buffer);
    return (0);
}
