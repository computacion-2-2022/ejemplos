#include <iostream>

#include "prodEscalar.cpp"

#define VECTOR_DIM 2

int main() {
    double v[VECTOR_DIM] = {1, 2}, w[VECTOR_DIM] = {3, 4}, rValue, rReference;

    rValue = prodEscalar(v, w, VECTOR_DIM);
    std::cout << "Producto escalar de [1, 2] y [3, 4] con paso por valor = " << rValue << std::endl;

    prodescalar(v, w, VECTOR_DIM, rReference);
    std::cout << "Producto escalar de [1, 2] y [3, 4] con paso por referencia = " << rReference << std::endl;

    return 0;
}
