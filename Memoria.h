#ifndef MEMORIA_H
#define MEMORIA_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Bloque {
    string nombre;  // nombre del proceso, o "Libre"
    int inicio;
    int tam;
};

enum TipoAlgoritmo { FIRST_FIT, BEST_FIT, WORST_FIT };

class Memoria {
private:
    int tamTotal;
    vector<Bloque> bloques;
    TipoAlgoritmo tipo;
    ofstream salida; // archivo de salida

public:
    Memoria(int tam, TipoAlgoritmo tipoAlg, const string& nombreArchivo);
    void asignar(const string& proceso, int tamano);
    void liberar(const string& proceso);
    void mostrar();
    void cerrarArchivo();
};

#endif
