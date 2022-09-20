#include <iostream>

int fibonacci(int);

int main() {
    int choice = 0;

    while (choice != -1) {
        std::cout << "Fibonacci sequence index [0, +inf): ";
        std::cin >> choice;
        if (choice == -1)
            break;
        else if (choice < 0 ) {
            std::cout << "The chosen index MUST be at least 0...\n";
            return -1;
        }
        std::cout << "Fib(" << choice << ") = " << fibonacci(choice) << std::endl;
    }

    std::cout << "Quitting...\n";
    return 0;
}

int fibonacci(int n) {
    if (n == 0 || n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
