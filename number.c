#include <stdio.h>

/**
 * main - prints the number of arguments passed into it.
 * @argc: Size of the argv array
 * @argv: Array of arguments
 * Return: 0 on Success
 */

int main(int argc, char *argv[])
{
	int num = 0;

	if (argc <= 1)
	{
		printf("%d\n", argc - 1);
	} else
	{
		while (argv[num] != '\0')
		{
			num++;
		}
		printf("%d\n", num - 1);
	}


	return (0);
}
