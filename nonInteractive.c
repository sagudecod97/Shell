#include "holberton.h"

int nonInteractive(char **env)
{
	size_t size = 69;
	char *buff = 0, **argum, **path;
	char **pathPrint;
	int i = 0;

	while(getline(&buff, &size, stdin) != EOF)
	{
		argum = _strtok1(buff); /** Returns an array of the tokens of buff **/
		pathPrint = cocaCommand(argum[0], env);
		if (forky(argum, buff, pathPrint, env) == -1)
			return (-1);
	}
	return (0);
}
