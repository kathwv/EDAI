#include <iostream>
#include <cstring>

#define TAM 4       // Número de películas
#define NUM_DIR 2   // Máximo de directores por película

struct pelicula {
    char nombre[30];
    char genero[20];
    int  anio;
    int  numDirectores;
    char directores[NUM_DIR][30];
};

int main() {
    pelicula videoteca[TAM];

    // pelicula 1: El castillo vagabundo
    std::strcpy(videoteca[0].nombre, "El castillo vagabundo");
    std::strcpy(videoteca[0].genero, "Animacion");
    videoteca[0].anio = 2004;
    videoteca[0].numDirectores = 1;
    std::strcpy(videoteca[0].directores[0], "Hayao Miyazaki");

    // pelicula 2: She All That
    std::strcpy(videoteca[1].nombre, "She All That");
    std::strcpy(videoteca[1].genero, "Romance");
    videoteca[1].anio = 1999;
    videoteca[1].numDirectores = 1;
    std::strcpy(videoteca[1].directores[0], "Robert Iscove");

    // pelicula 3: The Shining
    std::strcpy(videoteca[2].nombre, "The Shining");
    std::strcpy(videoteca[2].genero, "Terror");
    videoteca[2].anio = 1980;
    videoteca[2].numDirectores = 1;
    std::strcpy(videoteca[2].directores[0], "Stanley Kubrick");

    // pelicula 4: Soy leyenda
    std::strcpy(videoteca[3].nombre, "Soy leyenda");
    std::strcpy(videoteca[3].genero, "CienciaFiccion");
    videoteca[3].anio = 2007;
    videoteca[3].numDirectores = 1;
    std::strcpy(videoteca[3].directores[0], "Francis Lawrence");

    // orden inverso
    std::cout << " Contenido de la videoteca \n";
    for (int i = TAM - 1; i >= 0; i--) {
        std::cout << "Pelicula: " << videoteca[i].nombre << "\n";
        std::cout << "Genero: " << videoteca[i].genero << "\n";
        std::cout << "Anio: " << videoteca[i].anio << "\n";
        std::cout << "Directores (" << videoteca[i].numDirectores << "):\n";
        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            std::cout << "  - " << videoteca[i].directores[j] << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}
