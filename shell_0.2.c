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

        // Execute command with arguments
        execute_command(buffer);
    }

    free(buffer);
    return 0;
}
