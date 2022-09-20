void raicesPolGrado2(double a, double b, double c, double* R, int& n) {
    double delta = b * b - 4 * a * c;
    if (delta > 0) {
        n = 2;
        R[0] = (-b + sqrt(delta)) / (2 * a);
        R[1] = (-b - sqrt(delta)) / (2 * a);
    } else if (delta < 0) {
        n = 0;
    } else {
        n = 1;
        R[0] = -b / (2 * a);
    }
  return;
}
