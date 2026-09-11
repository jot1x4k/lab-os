#!/bin/bash

DIR="${1:-.}"

if [ ! -d "$DIR" ]; then
    echo "Error: '$DIR' no existe o no es un directorio." >&2
    exit 1
fi

convertidos=0
saltados=0

for archivo in "$DIR"/*.mkv; do
    [[ -e "$archivo" ]] || continue
    destino="${archivo%.mkv}.mp4"

    if [ -f "$destino" ]; then
        echo "Saltando: $archivo (el archivo .mp4 ya existe)"
        ((saltados++))
    else
        ffmpeg -i "$archivo" -c copy "$destino" -y -loglevel error
        if [ $? -eq 0 ]; then
            ((convertidos++))
        else
            echo "Error al convertir: $archivo" >&2
        fi
    fi
done

echo "Archivos convertidos: $convertidos"
echo "Archivos saltados: $saltados"