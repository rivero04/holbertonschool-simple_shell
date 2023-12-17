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
