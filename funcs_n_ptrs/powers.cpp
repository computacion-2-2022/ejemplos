#include <iostream>
#include <string>

double pow(double, double);

int main(int argc, char** argv) {
    double base, exponent;

    if (argc != 3) {
        std::cout << "usage: " << argv[0] << " base exponent\n";
        return -1;
    }

    try {
        base = std::stod(argv[1], NULL);
        exponent = std::stod(argv[2], NULL);
    } catch (std::invalid_argument const& ex) {
        std::cout << "error parsing the input arguments: " << ex.what() << '\n';
        return -1;
    }

    std::cout << base << " ^ " << exponent << " = " << pow(base, exponent) << std::endl;
    return 0;
}

double pow(double base, double exp) {
    if (!exp)
        return 1;
    return base * pow(base, exp - 1);
}
