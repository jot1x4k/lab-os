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

int info_proc(char *ruta, int argc);

#define MAX 1024

int main(int argc, char * argv[argc])
{
    char ruta[] = "/proc/";
    char self[] = "self";
    char aux[] = "/status";
    strcat(ruta,(argc > 1 ? argv[1] : self ));
    strcat(ruta, aux);

    int resultado = info_proc(ruta, argc);

    return resultado;
}

int info_proc(char *ruta, int argc)
{
    int fd = open(ruta, O_RDONLY);
    ssize_t bytes;

    if(fd < 0)
    {
        perror("Ocurrio un error al abrir el archivo del proceso");
        printf("%s\n", ruta);
        close(fd);
        return -1;
    }

    char buffer[MAX+1];

    read(fd, buffer, MAX);
    
    write(STDOUT_FILENO, buffer, MAX);
    
    close(fd);
}