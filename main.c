#include <stdio.h>
#include <stdlib.h>
#include "funciones.h" // <- Incluye tu encabezado
// También define funciones como convertir_a_grises(), convertir_a_ascii()...

unsigned char* imagen = NULL;
char** arte_ascii = NULL;
int ancho = 0;
int alto = 0;

int main(void) {
    char ruta[100];

    // === CARGAR IMAGEN ===
    printf("Ingresa la ruta de la imagen (.jpg, .png o .jpeg): ");
    scanf("%s", ruta);

    imagen = cargarImagen(ruta, &ancho, &alto);
    if (imagen == NULL) {
        printf("No se pudo cargar la imagen. Saliendo...\n");
        return 1;
    }

    // === MENU ===
    int opcion;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Convertir a escala de grises\n");
        printf("2. Convertir a arte ASCII\n");
        printf("3. Guardar resultado en archivo\n");
        printf("4. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                convertir_a_grises(imagen, ancho, alto); // <-- Usa tu función
                break;
            case 2:
                if (arte_ascii != NULL) {
                    for (int i = 0; i < alto; i++) free(arte_ascii[i]);
                    free(arte_ascii);
                }
                arte_ascii = convertir_a_ascii(imagen, ancho, alto); // <-- Usa tu función
                break;
            case 3:
                if (arte_ascii != NULL) {
                    guardar_ascii(arte_ascii, ancho, alto, "salida.txt"); // <-- Usa tu función
                } else {
                    printf("Primero debes convertir a ASCII.\n");
                }
                break;
            case 4:
                printf("Adiós!\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 4);

    // === LIBERAR MEMORIA ===
    liberarImagen(imagen); // Usa tu función
    if (arte_ascii != NULL) {
        for (int i = 0; i < alto; i++) free(arte_ascii[i]);
        free(arte_ascii);
    }

    return 0;
}