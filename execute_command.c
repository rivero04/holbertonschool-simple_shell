int execute_command(char **args)
{
    pid_t pid;
    int status;
    char *cmd = get_command(args[0]);

    if (cmd == NULL)
    {
        printf("Comando no encontrado\n");
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
        char *envp[] = {NULL}; 
        if (execve(cmd, args, envp) == -1)
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
