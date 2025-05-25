#include <stdio.h>
#include <stdlib.h>
#include "funciones.h" 


int main() {

            Imagen* usuarioImagen = cargarImagen();
            if(usuarioImagen != NULL){
                puts("================= Convertidor de Imagenes a Arte ASCII =================");
                //Se convierte la imagen del usuario a una imagen en escala de grises
                Imagen* imagenGris = convertir_a_grises(usuarioImagen, 100);
                //Se convierte la escala de grises a caracteres ASCII segun su brillo:
                char* arte = convertir_a_ascii(imagenGris);
                printf("%s", arte);
                char confirmacion;
                printf("Desea guardar la imagen?(Y/N)");
                scanf(" %c", &confirmacion);
                if(confirmacion == 'Y'|| confirmacion == 'y'){
                    guardar_ascii(arte, "salida.txt");
                    puts("Imagen guardada en salida.txt");
                }
                free(arte);
        }

    return 0;
}