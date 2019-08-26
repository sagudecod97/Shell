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
	size_t size = 69;
	char *buff, **argum, **path, **pathWhile;
	char **pathPrint, *dest, **pathOut;
	int i, j, c = 0, out = 0;
	pid_t pid;

	pathOut = getPath(env);

	while (EOF || out != 0) /** Wait till the signal EOF **/
	{
		buff = malloc(sizeof(char) * size); /** alloc memory to the buff **/
		if (buff == NULL)
		{
			free(buff);
		};
		write(1, "$ ", 3);
		fflush(stdin); /**clean the stdin**/
		c = getline(&buff, &size, stdin); /** Get what the user types **/
		if (c < 0)
      		{
			if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
				putchar('\n');
			free(buff);
			break;
		};

		argum = malloc(sizeof(char *) * 1024); /** Alloc the memory to every pointer **/

		if (argum == NULL)
		{
			free(argum);
			perror("Error ");
		};

		argum = _strtok1(buff); /** Returns an array of the tokens of buff **/
		path = pathOut;
		pathPrint = cocaCommand(argum[0], path);

		if (forky(argum, buff, pathPrint, env) == -1)
		{
			perror("./shell");
		}
	}

}
