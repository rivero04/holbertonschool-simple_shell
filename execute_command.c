#include "shell.h"

/**
 * execute_command - Execute a command.
 * @args: Array of strings containing the command and its arguments.
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
        fprintf(stderr, "Command not found: %s\n", args[0]);
        return -1;
    }

    printf("Executing command: %s\n", cmd);

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("Child process: PID=%d\n", getpid());
        if (execve(cmd, args, environ) == -1)
        {
            perror("execve");
            exit(2);
        }
    }
    else
    {
        printf("Parent process: Waiting for child (PID=%d) to complete...\n", pid);
        waitpid(pid, &status, 0);
        printf("Parent process: Child process (PID=%d) completed with status %d\n", pid, status);
    }

    free(cmd);
    return status;
}
