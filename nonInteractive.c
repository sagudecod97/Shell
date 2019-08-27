#include "holberton.h"

int nonInteractive(char **env)
{
	size_t size = 69;
	char *buff = 0, **argum, **path;
	char **pathPrint;
	int i = 0;

	path = getPath(env);

	while(getline(&buff, &size, stdin) != EOF)
	{
		argum = _strtok1(buff); /** Returns an array of the tokens of buff **/
		i = 0;
		while (path[i])
                {
                        printf("%s\n", path[i]);
                        i++;
                };
		i = 0;
		pathPrint = cocaCommand(argum[0], path);
		/*while (pathPrint[i])
		{
			printf("%s\n", pathPrint[i]);
			i++;
		}*/
		/*if (forky(argum, buff, pathPrint, env) == -1)
                        perror("./shell");*/
	}
	return (0);
}
