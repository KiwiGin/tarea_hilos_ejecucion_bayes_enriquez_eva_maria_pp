## 📚 Autor

BAYES ENRIQUEZ EVA MARIA FLORISA — Facultad de Ingeniería de Sistemas, UNMSM.

# 🔢 Búsqueda de Números Primos usando Hilos en C++

Este proyecto implementa dos enfoques para encontrar números primos hasta un número `N`:

- ✅ Búsqueda **secuencial**
- 🚀 Búsqueda **paralela** usando múltiples hilos (`std::thread`)

Está desarrollado en **C++17** y utiliza programación multihilo para demostrar las ventajas (y límites) del paralelismo.

---

## 🧠 Objetivos del Proyecto

- Comparar rendimiento entre ejecución secuencial y paralela.
- Utilizar `std::thread` para dividir el trabajo entre múltiples hilos.
- Entender cómo aprovechar múltiples núcleos del procesador en tareas computacionales.

---

## ⚙️ Requisitos

- C++17 o superior
- Compilador compatible con `std::thread` (GCC, Clang o MSVC)

---

## 🚀 Compilación

### Opción 1: Manual (g++)

```bash
 g++ main.cpp PrimoChecker.cpp BusquedaPrimosSecuencial.cpp BusquedaPrimosParalela.cpp -o AplicacionPrimos -std=c++17 -pthread
```

---

## ▶️ Ejecución

```bash
./AplicacionPrimos
```

Se solicitarán dos entradas:

- `N`: número hasta donde buscar primos.
- Número de hilos: cantidad de hilos para dividir el trabajo.

---

## 📝 Estructura de Archivos

```
.
├── main.cpp                        
├── PrimoChecker.h / .cpp
├── BusquedaPrimosSecuencial.h / .cpp
├── BusquedaPrimosParalela.h / .cpp
├── Makefile (opcional)
├── README.md
```

---

## 📈 Ejemplo de ENTRADA

```
Ingrese el valor de N: 10000000
Ingrese la cantidad de hilos: 6

```
El resultado muestra todos los primos encontrados y su tiempo de ejecución de c/caso.
Puede comentar las lineas 8,9 y 10 en el main.cpp y descomentar la linea 11 para solo obtener la cantidad de primos encontrados y el tiempo de ejecución de c/caso.
---


