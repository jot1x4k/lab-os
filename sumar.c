#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) 
{
	float a;
	float b;
	float total;

	if (argc != 3) /*	limitacion para sumar solo dos numeros	*/ 
	{
		fprintf(stderr, "Debe especificar dos numeros a sumar\n");
		exit(EXIT_FAILURE);
	}

	a = atof(argv[1]);
	b = atof(argv[2]);
	
	total = a + b;

	printf("%f\n", total);
	
	exit(EXIT_SUCCESS);
}

