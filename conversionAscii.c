#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "funciones.h"

char* convertir_a_ascii(Imagen* imagen_gris){
    if(imagen_gris == NULL || imagen_gris->canales != 1){
        return NULL;
    }

const char *caracteres = "@%#*+=-:. ";
int intensidad = strlen(caracteres);

    int ancho = imagen_gris->ancho;
    int alto = imagen_gris->alto;
    unsigned char* datos = imagen_gris->datos;

    int tamanoASCII = (ancho + 1) * alto + 1; // +1 por salto de línea, +1 por '\0'
    char* asciiArt = malloc(tamanoASCII);
    if(!asciiArt){
        return NULL;
    }

    int k = 0;
    for(int i = 0; i < alto; i++){
        for(int j = 0; j < ancho; j++){
            unsigned char pixel = datos[i * ancho + j];
            int indicePixel = (pixel * (intensidad - 1)) / 255;
            asciiArt[k++] = caracteres[indicePixel];
            asciiArt[k++] = caracteres[indicePixel]; // duplicado horizontal
        }
        asciiArt[k++] = '\n';
    }
    asciiArt[k] = '\0';
    return asciiArt;
}
