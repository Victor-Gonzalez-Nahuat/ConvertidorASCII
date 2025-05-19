#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

// Negro (0) — Gris oscuro (50) — Gris medio (128) — Gris claro (200) — Blanco (255)
char** convertir_a_ascii(unsigned char* imagen, int ancho, int alto) {
    const char* escala_ascii = "@#$*+=0:. "; // Escala de caracteres ASCII ordenados por brillo
    int niveles = 10; // Número de niveles de brillo en la escala
    
    // Reservar memoria para la matriz de arte ASCII
    char** arte_ascii = (char** )malloc(alto * sizeof(char*));
    if (arte_ascii == NULL) {
        printf("Error al asignar memoria para arte ASCII.\n");
        exit(1);
    }

    for (int i = 0; i < alto; i++) {
        arte_ascii[i] = (char*)malloc((ancho + 1) * sizeof(char)); // +1 para el carácter nulo
        if (arte_ascii[i] == NULL) {
            fprintf(stderr, "Error al asignar memoria para una línea de arte ASCII.\n");
            exit(1);
        }
    }//matriz de tamaño(alto)(ancho+1)

    // Convertir cada píxel a un carácter ASCII
    for (int y = 0; y < alto; y++) {
        for (int x = 0; x < ancho; x++) {
            unsigned char pixel = imagen[y * ancho + x]; // Obtener el valor del píxel
            int indice = (pixel * (niveles - 1)) / 255;  // Mapear el valor del píxel a la escala
            arte_ascii[y][x] = escala_ascii[indice];     // Asignar el carácter correspondiente
        }
        arte_ascii[y][ancho] = '\0'; // Terminar la línea con un carácter nulo
    }

    return arte_ascii; // Liberar la memoria de la matriz
}