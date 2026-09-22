#include <iostream>

int main() {
    std::cout << "--- [Day 04: Pointers & Dynamic Memory] ---" << std::endl;

    // 1. Basic Pointers
    int original = 1337;
    int* ptr = &original;

    std::cout << "Value of original: " << original << std::endl;
    std::cout << "Address of original: " << ptr << std::endl;
    std::cout << "Value via dereference (*ptr): " << *ptr << std::endl;

    *ptr = 2026;
    std::cout << "Modified value via pointer: " << original << std::endl;

    // 2. Dynamic Array on the Heap
    constexpr size_t SIZE = 6;
    int* heapArray = new int[SIZE]{10, 20, 30, 40, 50, 60};

    std::cout << "\nHeap Array elements via pointer arithmetic: ";
    for (size_t i = 0; i < SIZE; ++i) {
        std::cout << *(heapArray + i) << " ";
    }
    std::cout << std::endl;

    // 3. Two-pointer in-place reverse
    int* start = heapArray;
    int* end = heapArray + (SIZE - 1);
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        ++start;
        --end;
    }

    std::cout << "Reversed Heap Array: ";
    for (size_t i = 0; i < SIZE; ++i) {
        std::cout << heapArray[i] << " ";
    }
    std::cout << std::endl;

    // 4. Critical cleanup to avoid memory leak
    delete[] heapArray;
    heapArray = nullptr; // Reset to safe nullptr

    std::cout << "Memory successfully freed and pointer set to nullptr." << std::endl;
    return 0;
}
