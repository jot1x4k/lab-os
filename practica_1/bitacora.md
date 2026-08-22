# Bitacora del taller

## Integrantes

- Juan Jose Rodriguez Prada <juanrodriguezkq@unicauca.edu.co>

## Documentacion de la solucion

A continuacion se presenta una explicacion de los procedimientos que se realizaron para el cumplimiento de la practica de laboratorio.

### Programa 1
Para el primer programa se busco mediante la terminal de linux una entrada para el manual que tuviera relacion con las palabras clave **identificador**, **procesos** o similar. Esta accion llevo a una primera entrada del manual, la cual fue **id_t**.

```bash
man 3 id_t
```

En dicha entrada del manual, se encontro la siguiente informacion:

```
id_t is a type used to hold a general identifier.  It is an integer type that can be used to contain a pid_t, uid_t, or gid_t.
```

Donde se descubrio que en C existen unos tipos de datos que estan enfocados en almacenar informacion relacionada con los IDs y grupos de procesos. Continuando, se busco en la seccion SEE ALSO para obtener mas informacion al respecto. En esta seccion se encontraron dos metodos con nombres de gran interes, estos fueron **getpid(2)** y **getppid(2)**. 

Como su nombrado lo sugiere se puede interpretar que **getpid(2)** puede hacer referencia a *"get process id"* y a su vez, **getppid(2)** podria referirse a *"get parent process id"*. Procediendo, se realizo la busqueda de estos metodos en el manual para comprobar lo que se pensaba.

```bash
man getpid
```

```bash
man getppid
```

Tras la ejecucion, el manual arrojo una entrada con la informacion que se buscaba.

```bash
...

NAME
       getpid, getppid - get process identification

...

DESCRIPTION
       getpid()  returns the process ID (PID) of the calling process.
```
```bash
...

NAME
       getpid, getppid - get process identification

LIBRARY
       Standard C library (libc, -lc)
...

DESCRIPTION
       getpid()  returns the process ID (PID) of the calling process.
```

De esta manera se confirmo que efectivamente estos dos metodos que pertenecen a la libreria **<unistd.h>** permiten obtener el id del proceso y de su proceso padre.

Continuando, se solicito que se escribiera un mensaje por salida estandar usando **write** y no **printf** como se haria generalmente. Ademas, se exigio que se comprobara la validez de esta operacion manejando una salida de error si algo salia mal.

En primer lugar se accedio a la entrada de write en las llamadas al sistema.

```bash
man 2 write
```

```bash
...

NAME
       write - write to a file descriptor
...

SYNOPSIS
       #include <unistd.h>

       ssize_t write(int fd, const void buf[.count], size_t count);

DESCRIPTION
       write()  writes up to count bytes from the buffer starting at buf to the file referred to by the file descriptor fd.

...

RETURN VALUE
       On  success,  the  number of bytes written is returned.  On error, -1 is returned, and errno is set to indicate the error.
```

Esto indica que el funcionamiento del write es muy diferente al de printf. Primero, se solicita un parametro entero *fd* del cual no se tenia conocimiento. En la documentacion se menciona que hace referencia a un *file descriptor*.

Buscando ayuda se accedio a la entrada del manual de la salida estandar.

```bash
man stdout
```
Donde se encontro una referencia a los *file descriptors*

```bash
the  integer file descriptors associated with the streams stdin, stdout, and stderr are 0, 1, and  2,  respectively.   The preprocessor  symbols STDIN_FILENO, STDOUT_FILENO, and STDERR_FILENO are defined with these values in <unistd.h>.
```

Teniendo en cuenta esta informacion, se selecciono como la opcion candidato a **STDOUT_FILENO** para ser el valor de *fd* en la escritura con *write*, ya que hace referencia a la salida estandar.

Los parametros restantes fueron *buff* y *count*, donde *buff* es el mensaje que se definio como un arreglo de caracteres de longitud 50 y *count* seria la cantidad de caracteres diferentes al caracter nulo que esten dentro del arreglo.

El manejo de un posible error al usar *write* se logro de manera sencilla aprovechando el valor de retorno cuando sucede algun problema.

```c
if(write(STDOUT_FILENO, mensaje,  strlen(mensaje)) == -1) 
    { 
        perror("Ocurrio un error al usar la funcion WRITE.\n");
        exit(EXIT_FAILURE);
    }
```


### Programa 2

