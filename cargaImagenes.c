#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "funciones.h"

Imagen* cargarImagen() {
    char ruta[256];
    printf("Ingresa la ruta de la imagen (.jpg, .png o .jpeg): ");
    scanf("%255s", ruta);

    // Validar extensión
    const char* extension = strrchr(ruta, '.');
    if (!extension || (strcmp(extension, ".jpg") != 0 && strcmp(extension, ".png") != 0 && strcmp(extension, ".jpeg") != 0)) {
        printf("Error: Formato no soportado. Usa .jpg, .png o .jpeg\n");
        return NULL;
    }

    int ancho, alto, canales;
    unsigned char* datos = stbi_load(ruta, &ancho, &alto, &canales, 0);

    if (!datos) {
        printf("Error al cargar la imagen. Verifica la ruta.\n");
        return NULL;
    }

    // Si tiene canal alpha (RGBA), lo convertimos a RGB
    if (canales == 4) {
        unsigned char* imagen_rgb = (unsigned char*)malloc(ancho * alto * 3);
        if (!imagen_rgb) {
            printf("Error al asignar memoria.\n");
            stbi_image_free(datos);
            return NULL;
        }
        for (int i = 0, j = 0; i < ancho * alto * 4; i += 4, j += 3) {
            imagen_rgb[j]     = datos[i];     // R
            imagen_rgb[j + 1] = datos[i + 1]; // G
            imagen_rgb[j + 2] = datos[i + 2]; // B
        }
        stbi_image_free(datos);
        datos = imagen_rgb;
        canales = 3;
    }

    // Reservar memoria para la estructura
    Imagen* img = (Imagen*)malloc(sizeof(Imagen));
    if (!img) {
        printf("Error al asignar memoria para la estructura Imagen.\n");
        stbi_image_free(datos);
        return NULL;
    }

    img->ancho = ancho;
    img->alto = alto;
    img->canales = canales;
    img->datos = datos;

    printf("Imagen cargada: %dx%d, Canales: %d\n", ancho, alto, canales);
    return img;
}

// Libera la memoria de una Imagen
void liberarImagen(Imagen* imagen) {
    if (imagen) {
        free(imagen->datos); // Libera los pixeles
        free(imagen);        // Libera la estructura
    }
}
