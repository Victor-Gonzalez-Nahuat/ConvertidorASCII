#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

char* convertir_a_ascii(Imagen* imagen_gris){
  if(imagen_gris == NULL || imagen_gris->canales!=1){
    return NULL; //la imagen no esta en escala de grises
  }

  const char *caracteres=" .,:;Il!i><~+_-][}{1(()/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8B@$ ";
  int intensidad =  strlen(caracteres);
  //0 (negro) a 255 (blanco)
    
  int ancho = imagen_gris -> ancho;
  int alto = imagen_gris->alto;
  unsigned char* datos = imagen_gris->datos;

  int tamañoASCII = (ancho + 1) * alto + 1;
  char* asciiArt = malloc(tamañoASCII);
  if(!asciiArt){
    return NULL; //no hubo espacio en memoria, malloc falló
  }

  int k=0;
  for(int i = 0; i < alto; i++){
    for(int j = 0; j < ancho; j++){
      unsigned char pixel = datos[i*ancho+j]; //obtiene el valor del pixel en la posicion(i,j)
      int indicePixel = (pixel*(intensidad-1)/255); //convierte el valor del pixel a un indice del arreglo de caracteres
      asciiArt[k++] = caracteres[indicePixel];
    }
    asciiArt[k++] ='\n';
  }
  asciiArt[k] = '\0';
  return asciiArt;
}