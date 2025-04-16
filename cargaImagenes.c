#include <stdio.h>
#include <stdlib.h>  
#include <string.h> 
#define STB_IMAGE_IMPLEMENTATION 
#include "stb_image.h"            
#include "funciones.h"

unsigned char* cargarImagen(const char* ruta, int* ancho, int* alto) {
    const char* extension = strrchr(ruta, '.');
    if (!extension || (!strcmp(extension, ".jpg") && !strcmp(extension, ".png") && !strcmp(extension, ".jpeg"))) {
        printf("Error: Formato no soportado. Usa .jpg, .png o .jpeg\n");
        return NULL;
    }

    int canales;
    unsigned char* imagen = stbi_load(ruta, ancho, alto, &canales, 0);
    
    if (!imagen) {
        printf("Error al cargar la imagen. Verifica la ruta.\n");
        return NULL;
    }
    if (canales == 4) {
        unsigned char* imagen_rgb = (unsigned char*)malloc(*ancho * *alto * 3);
        for (int i = 0, j = 0; i < (*ancho * *alto * 4); i += 4, j += 3) {
            imagen_rgb[j] = imagen[i];     // R
            imagen_rgb[j+1] = imagen[i+1]; // G
            imagen_rgb[j+2] = imagen[i+2]; // B
        }
        stbi_image_free(imagen);
        imagen = imagen_rgb;
        canales = 3;
    }

    printf("Imagen cargada: %dx%d, Canales: %d\n", *ancho, *alto, canales);
    return imagen;
}

void liberarImagen(unsigned char* imagen) {
    stbi_image_free(imagen);  
}