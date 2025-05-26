#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void guardar_ascii(char* arte_ascii, const char* ruta_salida) {
    FILE* archivo = fopen(ruta_salida, "w");

    if (!archivo) {
        perror("Error al abrir el archivo para guardar el arte ASCII");
        return;
    }

    fprintf(archivo, "%s", arte_ascii);  // Escribe toda la cadena con saltos de línea incluidos
    fclose(archivo);

    printf("Arte ASCII guardado exitosamente en '%s'\n", ruta_salida);
}
