#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
/**
 * display_prompt - Displays the shell prompt
 */

void display_prompt(void)
{
	printf("#cisfun$ ");
}
/**
 * main - The entry point of the shell program
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char buffer[BUFFER_SIZE];

	while (1)
	{
		display_prompt();

		if (fgets(buffer, sizeof(buffer), stdin) == NULL)
		{
			printf("\n");

			break;
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		if (strcmp(buffer, "exit") == 0)
		{

			break;
		}

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			execlp(buffer, buffer, NULL);
			perror("exec");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
