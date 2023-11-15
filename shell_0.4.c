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

        // Check if the command is the exit built-in
        if (strcmp(buffer, "exit") == 0)
        {
            free(buffer);
            exit(EXIT_SUCCESS);
        }

        // Execute command with PATH handling
        execute_command_with_path(buffer);
    }

    free(buffer);
    return 0;
}
