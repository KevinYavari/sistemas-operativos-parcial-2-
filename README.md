# 🧠 Sistemas Operativos – Parcial II (2025-2)

Proyecto desarrollado por **Kevin Yavari Yoshioka** para el curso de Sistemas Operativos.  
Simula la **asignación dinámica de memoria** utilizando los algoritmos:

- First Fit  
- Best Fit  
- Worst Fit

Implementado en **C++ con Programación Orientada a Objetos (POO)**.

---

## 📘 Descripción

El programa recibe una secuencia de operaciones desde un archivo de texto (`entradaX.txt`) y genera **tres archivos de salida**:

- `salida_firstfit.txt`  
- `salida_bestfit.txt`  
- `salida_worstfit.txt`

Cada archivo muestra el comportamiento del algoritmo correspondiente sobre la **misma secuencia de operaciones**.

### ✅ Comandos disponibles

| Comando | Descripción                     |
|--------|----------------------------------|
| `A <tamaño>` | Asigna memoria a un proceso |
| `L`          | Libera el proceso indicado  |
| `M`          | Muestra el estado de memoria |

---

## ⚙️ Compilación y ejecución

Abre una terminal en la carpeta del proyecto y ejecuta:

```bash
g++ src/main.cpp src/Memoria.cpp -o memoria
./memoria
```

## 📝 Cómo cambiar el archivo de entrada

En `main.cpp`, por defecto se lee:

```cpp
ifstream entrada("entrada5.txt");
```

Para usar otro archivo, cambia el nombre:

```cpp
ifstream entrada("entrada2.txt");
```

Luego **guarda, recompila y ejecuta nuevamente.**

---

## 📊 Ejemplo de ejecución

**Entrada:**
A P1 10  
A P2 20  
L P1  
A P3 8  
M  

**Salida generada (First Fit):**

Asignado P1 (10)  
Asignado P2 (20)  
Liberado P1  
Asignado P3 (8)  
[P3:8][Libre:2][P2:20][Libre:70]

---

## 👤 Autor

**Kevin Yavari Yoshioka**  

