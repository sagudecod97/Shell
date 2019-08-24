#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "holberton.h"

/**
 * main - Entry point
 *
 * Return: 0 on Success
 */

int main(int argc, char **argv, char **env)
{
	size_t size = 0;
	char *buff, **argv;
	int i = 0, j;
	pid_t pid;

	while (EOF)
	{
		buff = malloc(sizeof(char) * size);
		if (buff == NULL)
		{
			free(buff);
		};
		printf("$ ");
		fflush(stdin);
		getline(&buff, &size, stdin);

		argv = malloc(sizeof(char *) * 1024);

		if (argv == NULL)
		{
			free(argv);
			perror("Error ");
		};

		argv = _strtok(buff);

		pid = fork();

		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("./shell");
			}
			exit(98);
		} else if (pid < 0)
			perror("./shell");
		else
			wait(&pid);
	}

}
