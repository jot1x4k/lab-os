/**
 * @file
 * @brief Crear dos procesos que ejecuten diferentes comandos, y verificar cual termina primero.
 * @authors Juan Jose Rodriguez Prada <juanrodriguezkq@unicauca.edu.co>
 *          Sebastian Tintinago Pantoja <sebastiantintinago@unicauca.edu.co>
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    switch (pid)
    {
    case -1:
        perror("Error al duplicar proceso...");
        exit(EXIT_FAILURE);
    case 0:
        printf("[%d] Rama HIJO 1\n", getpid());
        printf("[%d] HIJO 1: ejecutar 'ls -l'\n", getpid());

        execlp("ls", "ls", "-l", (char *)NULL);

        perror("Error al usar exec en hijo 1");
        exit(EXIT_FAILURE);

    default:
        printf("[%d] Rama PADRE\n", getpid());
        printf("[%d] PADRE: PID de HIJO 1: %d\n", getpid(), pid);

        pid_t pid_1 = fork();

        switch (pid_1)
        {
        case -1:
            perror("Error al clonar segundo hijo...");
            exit(EXIT_FAILURE);

        case 0:
            printf("[%d] Rama HIJO 2\n", getpid());
            printf("[%d] HIJO 2: ejecutar 'pwd -L'\n", getpid());

            execlp("pwd", "pwd", "-L", (char *)NULL);

            perror("Error al usar exec en hijo 2");
            exit(EXIT_FAILURE);

        default:
            printf("[%d] PADRE: PID de HIJO 2: %d\n", getpid(), pid_1);

            for (int i = 0; i < 2; i++)
            {
                int estado;
                pid_t wpid = waitpid(-1, &estado, 0);

                if (wpid < 0)
                {
                    perror("Error al esperar por el proceso");
                    exit(EXIT_FAILURE);
                }

                if (WIFEXITED(estado))
                {
                    if (i == 0)
                    {
                        printf("\n[%d] El proceso %d termino PRIMERO.\n", getpid(), wpid);
                    }
                    printf("[%d] Proceso %d terminó con codigo de salida: %d\n",
                           getpid(), wpid, WEXITSTATUS(estado));
                }
            }

            printf("[%d] PADRE TERMINANDO PROCESO\n", getpid());
            break;
        }
    }

    exit(EXIT_SUCCESS);
}