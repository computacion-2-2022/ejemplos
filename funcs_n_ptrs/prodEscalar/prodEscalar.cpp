double prodEscalar(double h[], double* p, int dim){
    double result = 0;
    for (int i = 0; i < dim; i++)
        result += h[i] * p[i];
    return result;
}

void prodescalar(double h[], double* p, int dim, double& result){
    result = 0;
    for (int i = 0; i < dim; i++)
        result +=  h[i] * p[i];
}
