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

        // Execute command with PATH handling
        execute_command_with_path(buffer);
    }

    free(buffer);
    return 0;
}

void execute_command_with_path(char *command)
{
    // Implement PATH handling here
}
