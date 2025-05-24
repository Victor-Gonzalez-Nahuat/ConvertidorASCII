#include <stdio.h>
#include <stdlib.h>
#include "funciones.h" // <- Incluye tu encabezado


int main() {
    Imagen* usuarioImagen = cargarImagen();
    if(usuarioImagen != NULL){
        //Se convierte la imagen del usuario a una imagen en escala de grises
        Imagen* imagenGris = convertir_a_grises(usuarioImagen, 100);
        //Se convierte la escala de grises a caracteres ASCII segun su brillo:
        char* arte = convertir_a_ascii(imagenGris);
        printf("%s", arte);
        guardar_ascii(arte, "salida.txt");
        free(arte);

    }
    return 0;
}