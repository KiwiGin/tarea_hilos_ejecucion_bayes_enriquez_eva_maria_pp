#include "BusquedaPrimosParalela.h"
#include "PrimoChecker.h"
#include <thread>
#include <algorithm>

std::vector<int> BusquedaPrimosParalela::encontrar(int N, int numHilos) {
    //vector que almacenará todos los objetos std::thread
    std::vector<std::thread> hilos;
    //vector de vectores donde cada hilo guardará sus primos localmente en resultados[i]
    std::vector<std::vector<int>> resultados(numHilos);
    //divide el rango [0, N] en partes iguales para cada hilo
    //bloque = tamaño de cada parte
    int bloque = (N + 1) / numHilos;

    for (int i = 0; i < numHilos; ++i) {
        //calcula el inicio y fin del rango para cada hilo
        int inicio = i * bloque;
        //el último hilo (i == 5) se asegura de cubrir hasta el final del rango incluso si hay un residuo
        int fin = (i == numHilos - 1) ? N + 1 : inicio + bloque;

        //emplace_back está creando un std::thread que ejecutará la lambda proporcionada, y ese hilo se agrega automáticamente al final del vector hilos. Cada hilo verifica un rango de números para determinar si son primos y guarda los resultados correspondientes en el vector resultados
        hilos.emplace_back([inicio, fin, &resultados, i]() {
            for (int n = inicio; n < fin; ++n)
                if (PrimoChecker::esPrimo(n))
                    //si es primo, se agrega al vector de resultados[i]
                    resultados[i].push_back(n);
        });
    }

    //espera a que todos los hilos terminen
    for (auto& hilo : hilos)
        hilo.join();
    //se combina todos los resultados en un solo vector
    std::vector<int> primos;
    for (auto& v : resultados)
        primos.insert(primos.end(), v.begin(), v.end());

    std::sort(primos.begin(), primos.end());
    return primos;
}
