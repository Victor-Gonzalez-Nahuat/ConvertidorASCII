#ifndef FUNCIONES_H
#define FUNCIONES_H

// Devuelve array de pixeles en formato RGB (3 canales) o escala de grises (1 canal).
// El arreglo se tiene que liberar de memoria con liberar_imagen() despues de usar cargarImagen
unsigned char* cargarImagen(const char* ruta, int* ancho, int* alto);
void liberarImagen(unsigned char* imagen);  

// Declaraciones de procesamiento.c (Kevin)
void convertir_a_grises(unsigned char* imagen, int ancho, int alto);

// Declaraciones de ascii.c (Natalia)
char** convertir_a_ascii(unsigned char* imagen, int ancho, int alto);

// Declaraciones de guardado.c (Roberto)
void guardar_ascii(char** arte_ascii, int ancho, int alto, const char* ruta_salida);

#endif