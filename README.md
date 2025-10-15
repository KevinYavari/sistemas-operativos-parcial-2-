🧠 Sistemas Operativos – Parcial II (2025-2)

Proyecto desarrollado por Kevin Yavari Yoshioka para el curso de Sistemas Operativos.
Simula la asignación dinámica de memoria utilizando los algoritmos First Fit, Best Fit y Worst Fit implementados en C++ con Programación Orientada a Objetos (POO).

📘 Descripción

El programa recibe una secuencia de operaciones de asignación, liberación y visualización de memoria desde un archivo de texto (entradaX.txt) y genera tres archivos de salida:

salida_firstfit.txt

salida_bestfit.txt

salida_worstfit.txt

Cada uno representa el comportamiento del respectivo algoritmo sobre la misma secuencia de operaciones.

Los comandos que entiende el programa son:
A <proceso> <tamaño>   // Asigna memoria al proceso
L <proceso>            // Libera el proceso indicado
M                      // Muestra el estado de la memoria
⚙️ Compilación y ejecución

Abre una terminal en la carpeta del proyecto.

Compila el programa con:

g++ src/main.cpp src/Memoria.cpp -o memoria

Ejecuta con:

./memoria

📝 Cómo cambiar el archivo de entrada

En el archivo main.cpp, el programa lee por defecto:

ifstream entrada("entrada5.txt");

Para usar otro archivo, solo cambia el nombre dentro de las comillas.
Por ejemplo, para ejecutar la entrada 2:

ifstream entrada("entrada2.txt");

Guarda los cambios, recompila y ejecuta de nuevo.

📊 Ejemplo de ejecución

Archivo de entrada:
A P1 10
A P2 20
L P1
A P3 8
M

Salida generada (First Fit):

Asignado P1 (10)
Asignado P2 (20)
Liberado P1
Asignado P3 (8)
[P3:8][Libre:2][P2:20][Libre:70]

👤 Autor

Kevin Yavari Yoshioka
Ingeniería de Sistemas
