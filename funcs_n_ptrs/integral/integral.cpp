double integral(double f(double), double a, double b, int n) {
    double suma = 0, delta = (b - a) / double(n);
    for (double i = a; i <= b; i += delta) {
        suma += f(i);
        // std::cout << suma << std::endl;
    }
    return delta * suma;
}
