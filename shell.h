#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void display_prompt(void);
void execute_command(char *command);
void execute_command_with_path(char *command);
void display_environment(void);

#endif /* SHELL_H */
