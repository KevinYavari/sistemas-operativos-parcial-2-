#include "Memoria.h"
#include <algorithm>

Memoria::Memoria(int tam, TipoAlgoritmo tipoAlg, const string& nombreArchivo) {
    tamTotal = tam;
    tipo = tipoAlg;
    bloques.push_back({"Libre", 0, tam}); // memoria inicial libre
    salida.open(nombreArchivo);
    salida << "Simulación con algoritmo: ";
    if (tipo == FIRST_FIT) salida << "First Fit\n";
    else if (tipo == BEST_FIT) salida << "Best Fit\n";
    else salida << "Worst Fit\n";
    salida << "Memoria total: " << tamTotal << " unidades\n\n";
}

void Memoria::asignar(const string& proceso, int tamano) {
    int idx = -1;

    if (tipo == FIRST_FIT) {
        for (int i = 0; i < (int)bloques.size(); i++) {
            if (bloques[i].nombre == "Libre" && bloques[i].tam >= tamano) {
                idx = i; break;
            }
        }
    } else if (tipo == BEST_FIT) {
        int minTam = 1e9;
        for (int i = 0; i < (int)bloques.size(); i++) {
            if (bloques[i].nombre == "Libre" && bloques[i].tam >= tamano && bloques[i].tam < minTam) {
                minTam = bloques[i].tam;
                idx = i;
            }
        }
    } else if (tipo == WORST_FIT) {
        int maxTam = -1;
        for (int i = 0; i < (int)bloques.size(); i++) {
            if (bloques[i].nombre == "Libre" && bloques[i].tam >= tamano && bloques[i].tam > maxTam) {
                maxTam = bloques[i].tam;
                idx = i;
            }
        }
    }

    if (idx == -1) {
        salida << "No hay espacio para asignar " << proceso << " (" << tamano << ")\n";
        return;
    }

    Bloque libre = bloques[idx];
    bloques.erase(bloques.begin() + idx);
    bloques.insert(bloques.begin() + idx, {proceso, libre.inicio, tamano});

    int restante = libre.tam - tamano;
    if (restante > 0)
        bloques.insert(bloques.begin() + idx + 1, {"Libre", libre.inicio + tamano, restante});

    salida << "Asignado " << proceso << " (" << tamano << ")\n";
}

void Memoria::liberar(const string& proceso) {
    for (int i = 0; i < (int)bloques.size(); i++) {
        if (bloques[i].nombre == proceso) {
            bloques[i].nombre = "Libre";
            salida << "Liberado " << proceso << "\n";
            // fusionar bloques libres contiguos
            if (i > 0 && bloques[i-1].nombre == "Libre") {
                bloques[i-1].tam += bloques[i].tam;
                bloques.erase(bloques.begin() + i);
                i--;
            }
            if (i + 1 < (int)bloques.size() && bloques[i+1].nombre == "Libre") {
                bloques[i].tam += bloques[i+1].tam;
                bloques.erase(bloques.begin() + i + 1);
            }
            return;
        }
    }
    salida << "No se encontró proceso " << proceso << " para liberar\n";
}

void Memoria::mostrar() {
    salida << "[";
    for (size_t i = 0; i < bloques.size(); i++) {
        salida << (bloques[i].nombre == "Libre" ? "Libre" : bloques[i].nombre)
               << ":" << bloques[i].tam << "]";
    }
    salida << "\n\n";
}

void Memoria::cerrarArchivo() {
    salida.close();
}
