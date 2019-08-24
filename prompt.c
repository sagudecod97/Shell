#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "holberton.h"

/**
 * main - Entry point
 *
 * Return: 0 on Success
 */

int main( __attribute__((unused)) int argc, __attribute__((unused)) char **argv, char **env)
{
	size_t size = 0;
	char *buff, **argum;
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

		argum = malloc(sizeof(char *) * 1024);

		if (argum == NULL)
		{
			free(argum);
			perror("Error ");
		};

		argum = _strtok1(buff);
		printf("%s\n", argum[0]);	
		pid = fork();

		if (pid == 0)
		{
			if (execve(argum[0], argum, NULL) == -1)
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
