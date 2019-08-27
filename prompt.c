#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "holberton.h"

/**
 * main - Entry point
 * @argc: Unused variable
 * @argv: Unused variable
 * Return: 0 on Success
 */

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
	size_t size = 69;
	char *buff, **argum, **path, **pathWhile;
	char **pathPrint, *dest, **pathOut, **env = environ;
	int i, j, c = 0, out = 0;
	pid_t pid;

	pathOut = getPath(env);
	if (isatty(STDIN_FILENO) != 1)
	{
		nonInteractive(pathOut);
		return (0);
	}

	while (c != EOF) /** Wait till the signal EOF **/
	{
		buff = malloc(sizeof(char) * size); /** alloc memory to the buff **/
		if (buff == NULL)
		{
			free(buff);
		};
		write(1, "$ ", 3);
		fflush(stdin); /**clean the stdin**/
		c = getline(&buff, &size, stdin); /** Get what the user types **/
		argum = malloc(sizeof(char *) * 1024); /** Alloc the memory**/
		if (argum == NULL)
		{
			free(argum);
			perror("Error ");
		};
		argum = _strtok1(buff); /** Returns an array of the tokens of buff **/
		path = pathOut;
		pathPrint = cocaCommand(argum[0], path);
		if (forky(argum, buff, pathPrint, env) == -1)
			perror("./shell");
	};
}
