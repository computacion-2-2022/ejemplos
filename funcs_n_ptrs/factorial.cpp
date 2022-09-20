#include <iostream>

long int factorialRecursive(long int);
long int factorialIterative(long int);

int main() {
    long int n = 0;
    std::cout << "Number to compute the factorial for: ";
    std::cin >> n;

    std::cout << n << "! = " << factorialRecursive(n) << " == " << factorialIterative(n) << std::endl;

    return 0;
}

long int factorialRecursive(long int n) {
    if (!n)
        return 1;
    return n * factorialRecursive(n - 1);
}


long int factorialIterative(long int n) {
    long int fact = 1;

    for (int i = n; i > 1; i--)
        fact *= i;

    return fact;
}
