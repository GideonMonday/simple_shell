#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Entry point for the simple shell program.
 *
 * Return: Always 0 on success.
 */
int main(void)
{
	char *command;
	size_t bufsize = 1024;
	int chars_read;

	while (1)
	{
		printf("#cisfun$ ");
		command = (char *)malloc(bufsize * sizeof(char));
		if (command == NULL)
		{
			perror("Allocation error");
			exit(EXIT_FAILURE);
		}

		chars_read = getline(&command, &bufsize, stdin);

		if (chars_read == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(command);
			exit(EXIT_SUCCESS);
		}
		command[chars_read - 1] = '\0';

		if (access(command, X_OK) == 0)
		{
			if (fork() == 0)
			{
				if (execve(command, NULL, NULL) == -1)
				{
					perror("Execution error");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(NULL);
			}
		}
		else
			void helper_function2(void)
			{
				fprintf(stderr, "%s: No such file or directory\n", command);
			}

		free(command);
	}

	return (0);
}
