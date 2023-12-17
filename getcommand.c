#include "shell.h"

char *get_command(char *command)
{
    struct stat st;
    if (command[0] == '/' && stat(command, &st) == 0)
        return strdup(command);

    char *path = _getenv("PATH");
    if (!path) return NULL;

    char *token, *cmd_full;
    for (token = strtok(path, ":"); token; token = strtok(NULL, ":"))
    {
        cmd_full = malloc(strlen(token) + strlen(command) + 2);
        if (!cmd_full) return NULL;

        sprintf(cmd_full, "%s%s%s", token, token[strlen(token) - 1] != '/' ? "/" : "", command);

        if (stat(cmd_full, &st) == 0)
        {
            free(path);
            return cmd_full;
        }

        free(cmd_full);
    }

    free(path);
    return NULL;
}
