#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"

Imagen* convertir_a_grises(Imagen* imagen_color, int nuevo_ancho) {
    if (!imagen_color || imagen_color->canales != 3) {
        printf("Error: Imagen inválida o no es RGB.\n");
        return NULL;
    }

    int ancho = imagen_color->ancho;
    int alto = imagen_color->alto;
    unsigned char* datos_rgb = imagen_color->datos;

    float escala = (float)nuevo_ancho / ancho;
    int nuevo_alto = (int)(alto * escala * 0.5);  // Corrección para proporciones de texto

    // Paso 1: Convertir a escala de grises sin escalar aún
    unsigned char* gris = (unsigned char*)malloc(ancho * alto);
    if (!gris) {
        printf("Error al asignar memoria para gris.\n");
        return NULL;
    }

    for (int i = 0; i < ancho * alto; i++) {
        int r = datos_rgb[i * 3 + 0];
        int g = datos_rgb[i * 3 + 1];
        int b = datos_rgb[i * 3 + 2];
        gris[i] = (unsigned char)(0.3 * r + 0.59 * g + 0.11 * b);
    }

    // Paso 2: Escalar la imagen en gris
    unsigned char* escalado = (unsigned char*)malloc(nuevo_ancho * nuevo_alto);
    if (!escalado) {
        printf("Error al asignar memoria para imagen escalada.\n");
        free(gris);
        return NULL;
    }

    float proporcion_x = (float)ancho / nuevo_ancho;
    float proporcion_y = (float)alto / nuevo_alto;

    for (int y = 0; y < nuevo_alto; y++) {
        for (int x = 0; x < nuevo_ancho; x++) {
            int x_original = (int)(x * proporcion_x);
            int y_original = (int)(y * proporcion_y);
            escalado[y * nuevo_ancho + x] = gris[y_original * ancho + x_original];
        }
    }

    free(gris);  // Ya no la necesitamos

    // Paso 3: Crear la nueva estructura Imagen
    Imagen* imagen_gris = (Imagen*)malloc(sizeof(Imagen));
    if (!imagen_gris) {
        printf("Error al asignar memoria para estructura Imagen gris.\n");
        free(escalado);
        return NULL;
    }

    imagen_gris->ancho = nuevo_ancho;
    imagen_gris->alto = nuevo_alto;
    imagen_gris->canales = 1;
    imagen_gris->datos = escalado;

    return imagen_gris;
}
