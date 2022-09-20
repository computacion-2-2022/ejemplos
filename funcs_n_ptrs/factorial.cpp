#include <iostream>

long int factorial(long int);

int main() {
    long int n = 0;
    std::cout << "Number to compute the factorial for: ";
    std::cin >> n;

    std::cout << n << "! = " << factorial(n) << std::endl;

    return 0;
}

long int factorial(long int n) {
    if (!n)
        return 1;
    return n * factorial(n - 1);
}
