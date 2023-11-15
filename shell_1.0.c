#include "shell.h"

int main(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;

    while (1)
    {
        display_prompt();

        // Read command from user
        getline(&buffer, &bufsize, stdin);

        // Remove newline character
        buffer[strcspn(buffer, "\n")] = '\0';

        // Check if the command is the env built-in
        if (strcmp(buffer, "env") == 0)
        {
            display_environment();
        }
        else
        {
            // Execute command with PATH handling
            execute_command_with_path(buffer);
        }
    }

    free(buffer);
    return 0;
}

void display_environment(void)
{
    extern char **environ;

    for (char **env = environ; *env != NULL; env++)
    {
        printf("%s\n", *env);
    }
}
