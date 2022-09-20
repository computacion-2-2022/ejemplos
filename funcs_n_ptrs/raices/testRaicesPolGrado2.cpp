#include <iostream>
#include <cmath>

#include "raicesPolGrado2.cpp"

#define A 2
#define B 4
#define C 1

int main() {
    int nRoots;
    double roots[2];

    raicesPolGrado2(A, B, C, roots, nRoots);

    std::cout << "Raíces para el polinomio de grado 2 con coeficientes A = " << A << "; B = " << B << "; C = " << C << ":\n";
    for(int i = 0; i < nRoots; i++)
        std::cout << "\tRaíz " << i + 1 << ": " << roots[i] << std::endl;

    return 0;
}
