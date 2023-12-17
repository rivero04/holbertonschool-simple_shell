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
