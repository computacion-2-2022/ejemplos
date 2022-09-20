double derivada(double f(double), double x, int mode, double h) {
    switch (mode) {
        case 0:
            return (f(x + h) - f(x)) / h;
        case 1:
            return (f(x + h) - f(x - h)) / (2 * h);
        case 2:
            return (8 * f(x + h) - 8 * f(x - h) - f(x + 2 * h) + f( x - 2 * h)) / (12 * h);
        case 3:
            {
                double s = (8 * f(x + h) - 8 * f(x - h) - f(x + 2 * h) + f(x - 2 * h)) / (12 * h);
                double s2 = (8 * f(x + 2 * h) - 8 * f(x - 2 * h) - f(x + 4 * h) + f(x - 4 * h)) / (24 * h);
                return (16 * s - s2) / 15;
            }
        default:
            return 0.0;
    }
}
