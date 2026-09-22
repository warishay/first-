#include <iostream>
#include <iomanip>
#include <limits>

int main() {
    std::cout << "--- [Day 01: C++ Basics & Data Types] ---" << std::endl;

    int a = 25;
    int b = 7;

    double divisionResult = static_cast<double>(a) / b;

    std::cout << "Integer a: " << a << ", Integer b: " << b << std::endl;
    std::cout << "Sum: " << (a + b) << std::endl;
    std::cout << "Difference: " << (a - b) << std::endl;
    std::cout << "Product: " << (a * b) << std::endl;
    std::cout << "Integer Quotient: " << (a / b) << std::endl;
    std::cout << "Modulus (Remainder): " << (a % b) << std::endl;
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Floating Division: " << divisionResult << std::endl;

    std::cout << "\nType Sizes on this system:" << std::endl;
    std::cout << "sizeof(bool): " << sizeof(bool) << " byte(s)\n";
    std::cout << "sizeof(char): " << sizeof(char) << " byte(s)\n";
    std::cout << "sizeof(int): " << sizeof(int) << " byte(s)\n";
    std::cout << "sizeof(float): " << sizeof(float) << " byte(s)\n";
    std::cout << "sizeof(double): " << sizeof(double) << " byte(s)\n";

    return 0;
}
