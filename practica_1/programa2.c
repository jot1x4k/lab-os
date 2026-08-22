/**
 * @file 
 * @brief 
 * @author Juan Jose Rodriguez Prada <juanrodriguezkq@unicauca.edu.co>
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[])
{
    char mensaje1[50] = "PRINTF: Este mensaje se debe repetir!";
    char mensaje2[50] = "WRITE: Este mensaje se debe repetir!";

    printf("%s", mensaje1);

    if(write(STDOUT_FILENO, mensaje2, strlen(mensaje2)) == -1) 
    { 
        perror("Ocurrio un error al usar la funcion WRITE.\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}