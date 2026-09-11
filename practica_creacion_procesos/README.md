## Taller: creación de procesos

## Laboratorio de Sistemas Operativos

Objetivo: crear procesos con fork, reemplazar la imagen de un proceso con exec y esperar su terminación con waitpid. Al terminar se entrega un programa que lanza comandos en procesos hijos, espera su final e informa con qué código terminaron.

## Punto de partida

Se supone resuelto: invocar llamadas al sistema desde C y verificar sus valores de retorno. Conviene tener presente qué devuelve fork en cada proceso, porque de ahí sale

toda la estructura del programa: al padre le devuelve el identificador del hijo, al hijo le devuelve cero, y a ambos les devuelve -1 si no pudo crear el proceso.

## Enunciado

- 1. Escribir un programa en C que cree un proceso hijo y distinga las tres ramas: error, hijo y padre. Cada rama informa quién es y cuál es su identificador de proceso.

- 2. Hacer que el hijo reemplace su imagen por un comando del sistema, con alguna función de la familia exec. El comando y sus argumentos se eligen libremente.

- 3. Añadir código después de la llamada a exec. Ejecutar el programa y explicar en la bitácora por qué ese código no se ejecuta, y en qué caso sí lo haría.

- 4. Hacer que el padre espere la terminación del hijo con waitpid e informe con qué código de salida terminó.

- 5. Extender el programa para que el padre cree dos hijos que ejecuten comandos distintos, espere a los dos e informe cuál terminó primero.

## Qué se entrega

- El programa en C, compilando sin advertencias con gcc -Wall.

- La bitácora, con la explicación del punto 3.


## Qué se valora

- Que las tres ramas de fork estén contempladas, incluida la de error.

- Que el terminador de la lista de argumentos de exec sea un apuntador nulo y no el entero cero.

- La explicación del punto 3, que muestra si se entendió qué hace exec con el proceso.

- Que el padre recoja a sus hijos y no queden procesos zombis.

## Errores frecuentes

- Interpretar mal el retorno de fork y ejecutar la rama del hijo en el padre.

- Terminar la lista de argumentos de exec con 0 en lugar de (char *)NULL. Puede funcionar por casualidad en una máquina y fallar en otra.

- Suponer que el código posterior a un exec correcto se ejecuta.

- Olvidar waitpid, o llamarlo por descuido dentro del hijo.
