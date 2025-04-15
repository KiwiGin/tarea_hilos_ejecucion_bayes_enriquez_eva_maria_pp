#include "PrimoChecker.h"
#include <cmath>

bool PrimoChecker::esPrimo(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= std::sqrt(n); i += 2)
        if (n % i == 0) return false;
    return true;
}
