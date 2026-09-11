# Taller: planificación de procesos

## Laboratorio de Sistemas Operativos

Objetivo: resolver a mano la planificación de un conjunto de procesos con tres algoritmos distintos y comparar sus resultados, y después observar en el sistema real cómo se reparte el procesador. Al terminar se entregan los tres diagramas de Gantt con sus tiempos calculados y una conclusión sobre cuál conviene en qué caso.

## Planteamiento del problema

Se supone conocido el concepto de planificación, la diferencia entre algoritmos expropiativos y no expropiativos, y el significado de tiempo de espera y tiempo de retorno. Recordar la distinción que más se confunde: el tiempo de espera es el que el proceso pasa en la cola de listos, sin usar el procesador. El tiempo de retorno

incluye además su ejecución.

## Primera parte: en papel

Dado el siguiente conjunto de procesos:

| Proceso | Llegada | Ráfaga |
|---------|---------|--------|
| P1      | 0       | 7      |
| P2      | 2       | 4      |
| P3      | 4       | 1      |
| P4      | 5       | 4      |


- 1. Resolver la planificación con FIFO, con SJF no expropiativo y con Round Robin con quantum igual a 2. Dibujar el diagrama de Gantt de cada uno.

- 2. Calcular, para cada algoritmo, el tiempo de espera y el tiempo de retorno de cada proceso, y sus promedios.

- 3. Comparar los tres resultados y responder: ¿cuál da el menor tiempo de espera promedio? ¿Ese algoritmo se puede usar tal cual en un sistema real? ¿Por qué?

- 4. Repetir el Round Robin con quantum igual a 1 y con quantum igual a 8. Explicar a qué se parece el resultado en cada extremo.



## Segunda parte: en la máquina

- 5. Observar los procesos en ejecución y sus prioridades:

```
\$ top
$ ps -eo pid,ni,pri,comm --sort=-pri | head
```

- 6. Lanzar un proceso que consuma procesador, cambiar su valor de amabili- dad con renice y describir qué cambia y qué no en la salida de top.

## Condiciones de entrega

- Los diagramas de Gantt y las tablas de tiempos, hechos a mano o en el computador.

- Las respuestas de los puntos 3, 4 y 6, en la bitácora.

## Criterios de valoración

- Que el cálculo del tiempo de espera no incluya la ejecución.

- Que el orden de llegada se respete cuando dos procesos empatan.

- La respuesta del punto 3: reconocer por qué el mejor resultado sobre el papel no es aplicable directamente.

## Errores frecuentes

- Sumar el tiempo de ejecución dentro del tiempo de espera.

- En Round Robin, olvidar que el proceso interrumpido vuelve al final de la cola.

- Interpretar que un valor de amabilidad más alto significa más prioridad. Es al revés: cuanto más amable, más cede el procesador.