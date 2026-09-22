#include <iostream>

// Pass-by-reference swap
void swapNumbers(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Overloaded functions for area calculation
double calculateArea(double radius) {
    constexpr double PI = 3.141592653589793;
    return PI * radius * radius;
}

double calculateArea(double width, double height) {
    return width * height;
}

// Recursive Euclidean algorithm for Greatest Common Divisor
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    std::cout << "--- [Day 03: Functions & Recursion] ---" << std::endl;

    int x = 10, y = 50;
    std::cout << "Before swap: x=" << x << ", y=" << y << std::endl;
    swapNumbers(x, y);
    std::cout << "After swap:  x=" << x << ", y=" << y << std::endl;

    std::cout << "Circle Area (r=5.0): " << calculateArea(5.0) << std::endl;
    std::cout << "Rectangle Area (w=4, h=7): " << calculateArea(4.0, 7.0) << std::endl;

    int num1 = 48, num2 = 18;
    std::cout << "GCD of " << num1 << " and " << num2 << " is: " << gcd(num1, num2) << std::endl;

    return 0;
}
