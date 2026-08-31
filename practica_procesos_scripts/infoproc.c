/**
 * @file 
 * @brief 
 * @author Juan Jose Rodriguez Prada <juanrodriguezkq@unicauca.edu.co>
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int info_proc(char *ruta);
void separar_cadena(char *cadena, char *separador, char **arr);

#define MAX 1024

int main(int argc, char * argv[argc])
{
    char ruta[] = "/proc/";
    char self[] = "self";
    char aux[] = "/status";
    strcat(ruta,(argc > 1 ? argv[1] : self ));
    strcat(ruta, aux);

    int resultado = info_proc(ruta);

    return resultado;
}

int info_proc(char *ruta)
{
    int fd = open(ruta, O_RDONLY);

    if(fd < 0)
    {
        perror("Ocurrio un error al abrir el archivo del proceso");
        printf("%s\n", ruta);
        close(fd);
        return -1;
    }

    char buffer[MAX];    
    ssize_t bytes = read(fd, buffer, MAX-1);

    if(bytes>0) buffer[bytes] = '\0';

    char *lineas[MAX];
    separar_cadena(buffer, "\n", lineas);
    
    printf("INFORMACION DEL PROCESO [%s]\n", ruta);
    printf("%s\n", lineas[0]);
    printf("%s\n", lineas[2]);
    printf("%s\n", lineas[5]);
    printf("%s\n", lineas[6]);
    printf("%s\n", lineas[36]);

    close(fd);
}

void separar_cadena(char *cadena, char *separador, char **arr)
{
    char *subcadena = strtok(cadena, separador); 
    int i = 0;
    
    while (subcadena != NULL) 
    {
        arr[i] = subcadena;   
        subcadena = strtok(NULL, separador); 
        i++;
    }

    arr[i] = NULL;
}