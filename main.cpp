#include "Memoria.h"
#include <fstream>
#include <sstream>

int main() {
    ifstream entrada("entrada5.txt");
    if (!entrada.is_open()) {
        cerr << "Error: no se pudo abrir entrada.txt\n";
        return 1;
    }

    int tamMem = 100; // puede modificarse
    Memoria firstFit(tamMem, FIRST_FIT, "salida_firstfit.txt");
    Memoria bestFit(tamMem, BEST_FIT, "salida_bestfit.txt");
    Memoria worstFit(tamMem, WORST_FIT, "salida_worstfit.txt");

    string linea;
    while (getline(entrada, linea)) {
        if (linea.empty()) continue;
        stringstream ss(linea);
        char op; ss >> op;

        if (op == 'A') {
            string nombre; int tam;
            ss >> nombre >> tam;
            firstFit.asignar(nombre, tam);
            bestFit.asignar(nombre, tam);
            worstFit.asignar(nombre, tam);
        } 
        else if (op == 'L') {
            string nombre;
            ss >> nombre;
            firstFit.liberar(nombre);
            bestFit.liberar(nombre);
            worstFit.liberar(nombre);
        } 
        else if (op == 'M') {
            firstFit.mostrar();
            bestFit.mostrar();
            worstFit.mostrar();
        }
    }

    firstFit.cerrarArchivo();
    bestFit.cerrarArchivo();
    worstFit.cerrarArchivo();
    entrada.close();

    cout << "Simulación completada. Archivos generados:\n";
    cout << " - salida_firstfit.txt\n - salida_bestfit.txt\n - salida_worstfit.txt\n";
    return 0;
}
