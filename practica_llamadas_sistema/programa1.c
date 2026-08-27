/**
 * @file 
 * @brief Programa 1 - Obtiene el identificador del proceso actual y su proceso padre, se imprime un mensaje 
 *        desde un llamado al sistema mediante write(2) y se retorna un valor diferente de 0.
 * @author Juan Jose Rodriguez Prada <juanrodriguezkq@unicauca.edu.co>
 * @author Sebastian Tintinago Pantoja <sebastiantintinago@unicauca.edu.co>
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[])
{
    int pId = 0, pIdPadre = 0;
    char mensaje[] = "Hola mundo! Escrito con WRITE.\n";

    pId = getpid();
    pIdPadre = getppid();

    printf("Identificador de proceso: %d\n", pId);
    printf("Identificador de proceso padre: %d\n", pIdPadre);

    if(write(STDOUT_FILENO, mensaje,  sizeof(mensaje)) == -1) 
    { 
        perror("Ocurrio un error al usar la funcion WRITE.\n");
        exit(EXIT_FAILURE);
    }

    exit(50);
}