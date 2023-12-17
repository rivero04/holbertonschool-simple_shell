#include "shell.h"
/**
 * printenv - Imprime todas las variables de entorno.
 */
void printenv(void)
{
	while (*environ != NULL)
	{
		printf("%s\n", *environ);
		environ++;
	}
}
