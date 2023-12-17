#include "shell.h"
/**
 * execute_command - Execute a command.
 * @args: Array of strings containing the command and its arguments.
 * @env: Array of strings containing the environment variables.
 *
 * Description:
 * This function forks a new process to execute a command specified in @args.
 * It retrieves the full path of the command using the get_command function.
 * The child process then attempts to execute the command using execve.
 * If successful, the child process is replaced with the specified command.
 * The parent process waits for the child process to complete.
 *
 * Return: No return value.
 */
int execute_command(char **args)
{
    pid_t pid;
    int status;
    char *cmd = get_command(args[0]);

    if (cmd == NULL)
    {
        printf("Command not found\n");
        return (-1);
    }

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        if (execve(cmd, args, environ) == -1)
        {
            perror("execve");
            exit(2);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
    }

    free(cmd);
    return status;
}

/**
 * Searches for an executable command in the PATH.
 *
 * Returns the full path if found, otherwise returns NULL.
 */
char *findCommandInPath(char *command_path) {
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
int executeWithPath(char *command_path, char **array) 
{
    int return_value = 0;
    struct stat perms;

    if (stat(command_path, &perms) == 0) 
    {
        return_value = execute_command(array[0], array);
        return return_value;
    } 
    else 
    {
        command_path = findCommandInPath(array[0]);
        if (command_path == NULL) 
        {
            printf("./hsh: 1: %s: not found", array[0]);
            return -1;
        }

        array[0] = command_path;

        if (stat(array[0], &perms) == 0) 
        {
            return_value = execute_command(array[0], array);
        }

        free(command_path);
        return return_value;
    }
    return -1;
}
