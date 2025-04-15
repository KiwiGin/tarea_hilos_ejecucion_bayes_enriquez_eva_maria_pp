#ifndef BUSQUEDA_PRIMOS_PARALELA_H
#define BUSQUEDA_PRIMOS_PARALELA_H

#include <vector>

class BusquedaPrimosParalela {
public:
    static std::vector<int> encontrar(int N, int numHilos);
};

#endif
