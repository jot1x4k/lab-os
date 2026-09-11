# Taller: Procesos, Scripts y Llamadas al Sistema

Este repositorio contiene la solucion al laboratorio de Sistemas Operativos. El objetivo es observar procesos vivos desde el shell y mediante llamadas al sistema en C, ademas de automatizar la conversion de videos con un script de shell.

## Estructura del Proyecto

*   **`infoproc.sh`**: Script de shell que informa sobre un proceso especifico (o el actual) leyendo `/proc/PID/status`. Recorre la cadena de padres hasta el proceso 1.
*   **`infoproc.c`**: Programa en C que realiza la misma tarea que `infoproc.sh`, pero utilizando exclusivamente llamadas al sistema (`open`, `read`, `close`) para leer los archivos de `/proc`.
*   **`convertir.sh`**: Script de administracion que convierte archivos `.mkv` a `.mp4` usando `ffmpeg`. Maneja directorios personalizados, evita sobrescrituras y reporta estadisticas.
*   **`Makefile`**: Automatiza la compilacion de `infoproc.c` sin advertencias (`gcc -Wall`).
*   **`bitacora.md`**: Explicaciones tecnicas sobre la coincidencia de datos entre el shell y C, el comportamiento de `/proc` y el flujo de ejecucion del shell.
*   **Capturas (`resources/imageN.png`)**: Evidencia de la ejecucion desde el usuario institucional creado para la practica.

## Requisitos

*   Maquina virtual Linux con privilegios de administrador (`sudo`).
*   Herramientas instaladas: `gcc`, `make`, `ffmpeg`.
*   Usuario institucional creado y agregado al grupo `sudo`.

## Compilacion y Ejecucion

### 1. Informacion de Procesos

**Script de Shell:**
```bash
chmod +x infoproc.sh
./infoproc.sh [PID] # Si no se pasa PID, usa el proceso actual
```

**Programa en C:**
```bash
make
./infoproc [PID] # Si no se pasa PID, usa el proceso actual
make clean # Limpia el ejecutable
```

### 2. Conversion de Videos

Generar archivos de prueba:
```bash
ffmpeg -f lavfi -i testsrc=duration=3:size=320x240 clase1.mkv
# Repetir para generar al menos 4 archivos, incluyendo uno con múltiples puntos (ej: clase.2026.mkv)
```

Ejecutar el script de conversion:
```bash
chmod +x convertir.sh
./convertir.sh [DIRECTORIO_OPCIONAL]
```
*Nota: Ejecutar dos veces seguidas para verificar que la segunda vez salta los archivos ya convertidos sin errores.*