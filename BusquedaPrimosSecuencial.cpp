#include "BusquedaPrimosSecuencial.h"
#include "PrimoChecker.h"

std::vector<int> BusquedaPrimosSecuencial::encontrar(int N) {
    std::vector<int> primos;
    for (int i = 0; i <= N; ++i)
        if (PrimoChecker::esPrimo(i))
            primos.push_back(i);
    return primos;
}
