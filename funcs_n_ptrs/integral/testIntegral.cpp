#include <iostream>
#include <cmath>

#include "integral.cpp"

#define A 2.0
#define B 3.0
#define N_INTERVALOS 10000

double f(double x) {
    return x * exp(-x);
}

double g(double x) {
    return x;
}

int main() {
    std::cout << "Integral de f(x) en [" << A << ", " << B << "] = " << integral(f, A, B, N_INTERVALOS) << std::endl;
    std::cout << "Integral de g(x) en [" << A << ", " << B << "] = " << integral(g, A, B, N_INTERVALOS) << std::endl;
    std::cout << "Integral de sin(x) en [0, PI] = " << integral(sin, 0, acos(-1), N_INTERVALOS) << std::endl;
    std::cout << "Integral de sin(x) en [0, 2 * PI] = " << integral(sin, 0, 2 * acos(-1), N_INTERVALOS) << std::endl;

    return 0;
}
