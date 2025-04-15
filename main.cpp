#include <iostream>
#include <chrono>
#include "BusquedaPrimosSecuencial.h"
#include "BusquedaPrimosParalela.h"

void mostrarResultados(const std::string& metodo, const std::vector<int>& primos,
                       std::chrono::duration<double, std::milli> duracion) {
    std::cout << "\n[" << metodo << "] Primos encontrados: ";
    for (int p : primos)
        std::cout << p << " ";
    // std::cout << "\n[" << metodo << "] Se encontraron " << primos.size() << " primos.\n";
    std::cout << "\nTiempo de ejecucion: " << duracion.count() << " ms\n";
}

int main() {
    int N, numHilos;

    std::cout << "Ingrese el valor de N: ";
    std::cin >> N;

    std::cout << "Ingrese la cantidad de hilos: ";
    std::cin >> numHilos;

    //secuencial
    auto inicioSec = std::chrono::high_resolution_clock::now();
    auto primosSec = BusquedaPrimosSecuencial::encontrar(N);
    auto finSec = std::chrono::high_resolution_clock::now();
    mostrarResultados("Secuencial", primosSec, finSec - inicioSec);

    //paralelo
    auto inicioPar = std::chrono::high_resolution_clock::now();
    auto primosPar = BusquedaPrimosParalela::encontrar(N, numHilos);
    auto finPar = std::chrono::high_resolution_clock::now();
    mostrarResultados("Paralelo", primosPar, finPar - inicioPar);

    return 0;
}
