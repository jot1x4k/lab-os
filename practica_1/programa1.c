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
    int pId = 0, pIdPadre = 0;
    char mensaje[50] = "Hola mundo! Escrito con WRITE.\n";

    pId = getpid();
    pIdPadre = getppid();

    printf("Identificador de proceso: %d\n", pId);
    printf("Identificador de proceso padre: %d\n", pIdPadre);

    if(write(STDOUT_FILENO, mensaje,  strlen(mensaje)) == -1) 
    { 
        perror("Ocurrio un error al usar la funcion WRITE.\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}