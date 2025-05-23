#ifndef FUNCIONES_H
#define FUNCIONES_H

// 📦 Estructura principal para todas las imágenes
typedef struct {
    int ancho;
    int alto;
    int canales;            // 3 para RGB, 1 para escala de grises
    unsigned char* datos;   // Arreglo dinamico de píxeles
} Imagen;

// 🖼️ Cargar imagen desde ruta pedida al usuario
// Devuelve puntero a Imagen con datos cargados en RGB
Imagen* cargarImagen();

// 🧼 Libera la memoria reservada para una Imagen
void liberarImagen(Imagen* imagen);

// 🎨 Convierte imagen RGB a escala de grises y la escala para que quepa en terminal
// Devuelve nueva Imagen en escala de grises
Imagen* convertir_a_grises(Imagen* imagen_color, int nuevo_ancho);

// 🔡 Convierte imagen en escala de grises a arte ASCII
// Devuelve un `char*` con todos los caracteres ASCII listos para mostrar o guardar
char* convertir_a_ascii(Imagen* imagen_gris);

// 💾 Guarda arte ASCII en archivo .txt (el usuario pone el nombre)
void guardar_ascii(char* arte_ascii, const char* ruta_salida);
// 📋 Menú de navegación del programa
void menu(void);

#endif
