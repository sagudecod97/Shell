#include "holberton.h"

/**
 * exitEnvBuilt - builtins for env and exit
 * @env: Enviroment variables
 * @argum: Argv[0]
 * Return: 0 on Success, -1 on failure
 */ 

int exitEnvBuilt(char **env, char *argum)
{
	int res;
	int i = 0, j = 0, count = 0;

	if (env == NULL || argum == NULL)
	{
		return(-1);
	};
	if (_strcmp(argum, "env") == 0)
	{
		while (env[i] != NULL)
		{
			count = _strLen(env[i]);
			while (j <= count)
			{
				_putchar(env[i][j]);
				j++;
			};
			i++;
		};
	}

	return (0);
}
