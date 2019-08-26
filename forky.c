#include "holberton.h"

/**
 * forky - Executes the fork
 * @argum: Array of pointers
 * @buff: String obtained through getline
 * @path: The tokens of path
 * Return: 0 on succes, -1 on failure
 */

int forky(char **argum, char *buff, char **path)
{
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		if (argum[0][0] == '/')
		{
			if (execve(argum[0], argum, NULL) == -1)
			{
				perror("./shell");
			};
		} 
		else
		{
			while (access(path[i], X_OK | F_OK) != 0)
				i++;
			execve();
		}
		return(-1);
	} else if (pid < 0)
	{
		return (-1);
	}else
	{
		wait(&pid);
	};
	return (0);
}
