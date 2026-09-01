/**
 * @file 
 * @brief Parse and display specific process status fields from /proc
 * @author Juan Jose Rodriguez Prada <juanrodriguezkq@unicauca.edu.co>
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH 512
#define MAX_BUF 4096

int info_proc(const char *ruta);

int main(int argc, char *argv[])
{
    char ruta[MAX_PATH];
    const char *pid = (argc > 1) ? argv[1] : "self";

    snprintf(ruta, sizeof(ruta), "/proc/%s/status", pid);

    return info_proc(ruta);
}

int info_proc(const char *ruta)
{
    int fd = open(ruta, O_RDONLY);
    if (fd < 0)
    {
        perror("Error al abrir el archivo del proceso");
        return -1;
    }

    char buffer[MAX_BUF];
    ssize_t bytes = read(fd, buffer, sizeof(buffer) - 1);
    close(fd);

    if (bytes < 0)
    {
        perror("Error al leer el archivo");
        return -1;
    }

    buffer[bytes] = '\0';

    const char *keys[] = {
        "Name:",
        "State:",
        "Pid:",
        "PPid:",
        "Threads:"
    };
    size_t num_keys = sizeof(keys) / sizeof(keys[0]);

    printf("INFORMACION DEL PROCESO [%s]\n", ruta);

    for (size_t i = 0; i < num_keys; i++)
    {
        char *pos = strstr(buffer, keys[i]);
        if (pos != NULL)
        {
            char *end = strchr(pos, '\n');
            if (end != NULL)
            {
                printf("%.*s\n", (int)(end - pos), pos);
            }
            else
            {
                printf("%s\n", pos);
            }
        }
    }

    return 0;
}