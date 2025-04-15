#include "BusquedaPrimosParalela.h"
#include "PrimoChecker.h"
#include <thread>
#include <algorithm>

std::vector<int> BusquedaPrimosParalela::encontrar(int N, int numHilos) {
    std::vector<std::thread> hilos;
    std::vector<std::vector<int>> resultados(numHilos);
    int bloque = (N + 1) / numHilos;

    for (int i = 0; i < numHilos; ++i) {
        int inicio = i * bloque;
        int fin = (i == numHilos - 1) ? N + 1 : inicio + bloque;

        hilos.emplace_back([inicio, fin, &resultados, i]() {
            for (int n = inicio; n < fin; ++n)
                if (PrimoChecker::esPrimo(n))
                    resultados[i].push_back(n);
        });
    }

    for (auto& hilo : hilos)
        hilo.join();

    std::vector<int> primos;
    for (auto& v : resultados)
        primos.insert(primos.end(), v.begin(), v.end());

    std::sort(primos.begin(), primos.end());
    return primos;
}
