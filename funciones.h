#ifndef FUNCIONES_H
#define FUNCIONES_H

//Estructura Imagen
typedef struct {
    int ancho;
    int alto;
    int canales;            // 3 para RGB, 1 para escala de grises
    unsigned char* datos;
} Imagen;

// Devuelve puntero a Imagen con datos cargados en RGB
Imagen* cargarImagen();

void liberarImagen(Imagen* imagen);

// Devuelve nueva Imagen en escala de grises
Imagen* convertir_a_grises(Imagen* imagen_color, int nuevo_ancho);

// Devuelve un char* con todos los caracteres ASCII para iimprimir o guardar
char* convertir_a_ascii(Imagen* imagen_gris);

//Guarda en un txt, no devuelve nada
void guardar_ascii(char* arte_ascii, const char* ruta_salida);

void menu(void);

#endif
