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
	int i, j;
	pid_t pid;

	pathOut = getPath(env);

	while (EOF) /** Wait till the signal EOF **/
	{
		buff = malloc(sizeof(char) * size); /** alloc memory to the buff **/
		if (buff == NULL)
		{
			free(buff);
		};
		printf("$ ");
		fflush(stdin); /** clean the stdin **/
		getline(&buff, &size, stdin); /** Get what the user types **/

		argum = malloc(sizeof(char *) * 1024); /** Alloc the memory to every pointer **/

		if (argum == NULL)
		{
			free(argum);
			perror("Error ");
		};

		argum = _strtok1(buff); /** Returns an array of the tokens of buff **/
		path = pathOut;
		/**pathWhile = path;**/
		/**pathPrint = cocaComand(argum[0], path);**/

		i = 0;

		while (path[i])
		{
			/**dest = strcat(pathWhile[i], argum[0]);**/
			printf("%s\n", path[i]);
			i++;
		};
	}

}
