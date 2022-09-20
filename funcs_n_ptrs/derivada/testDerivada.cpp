#include <iostream>
#include <cmath>

#include "derivada.cpp"

#define X 2.5
#define MODE 0
#define EPSILON 0.0001

double f(double x) {
    return x * exp(-x);
}

int main() {
    std::cout << "Derivada de f(x) para x = " << X << ": " << derivada(f, X, MODE, EPSILON) << std::endl;
    return 0;
}
