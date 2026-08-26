/**
 * @file 
 * @brief Programa 2 - Imprime el mismo mensaje mediante el llamado al sistema con write(2) y el uso de
 *        printf de la libreria de C.
 * @author Juan Jose Rodriguez Prada <juanrodriguezkq@unicauca.edu.co>
 * @author Sebastian Tintinago Pantoja <sebastiantintinago@unicauca.edu.co>
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[])
{
    char mensaje[] = "Este mensaje se debe repetir!";

    printf("%s", mensaje);

    if(write(STDOUT_FILENO, mensaje, sizeof(mensaje)) == -1) 
    { 
        perror("Ocurrio un error al usar la funcion WRITE.\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}