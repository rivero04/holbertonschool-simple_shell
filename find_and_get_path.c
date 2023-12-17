/**
 * Searches for an executable command in the PATH.
 *
 * Returns the full path if found, otherwise returns NULL.
 */
char *findCommandInPath(char *command_path) 
{
    char *path_token, *path = getenv("PATH");

    if (path == NULL) {
        fprintf(stderr, "Error: PATH environment variable is not set\n");
        return NULL;
    }

    path_token = strtok(path, ":");
    while (path_token != NULL) {
        char *full_path = malloc(strlen(path_token) + strlen(command_path) + 2);
        if (full_path == NULL) {
            fprintf(stderr, "Error: Failed to allocate memory\n");
            return NULL;
        }

        sprintf(full_path, "%s/%s", path_token, command_path);

        if (access(full_path, X_OK) == 0) {
            return full_path;
        }

        free(full_path);
        path_token = strtok(NULL, ":");
    }

    return NULL;
}

/**
 * Execute a command using the given command path and arguments.
 *
 * Returns the exit status of the command.
 */
int executeWithPath(char *command_path, char **array) {
    int return_value = 0;
    struct stat perms;

    if (stat(command_path, &perms) == 0) {
        return_value = executeCommand(array[0], array);
        return return_value;
    } else {
        command_path = findCommandInPath(array[0]);
        if (command_path == NULL) {
            printf("./hsh: 1: %s: not found", array[0]);
            return -1;
        }

        array[0] = command_path;

        if (stat(array[0], &perms) == 0) {
            return_value = executeCommand(array[0], array);
        }

        free(command_path);
        return return_value;
    }

    return -1;
}
