/**
 * cp_file - Copy a file using the system command.
 * @source: The path of the source file.
 * @destination: The path of the destination file.
 *
 * Return: 0 on success, -1 on failure.
 */
int cp_file(const char *source, const char *destination)
{
    char command[100];
    snprintf(command, sizeof(command), "cp %s %s", source, destination);
    return system(command);
}
