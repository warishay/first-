#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <numeric>

// 1. Generic Class Template
template <typename T>
class SimpleStack {
private:
    std::vector<T> elements;

public:
    void push(const T& item) {
        elements.push_back(item);
    }

    T pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack is empty!");
        }
        T top = elements.back();
        elements.pop_back();
        return top;
    }

    bool empty() const { return elements.empty(); }
    size_t size() const { return elements.size(); }
};

int main() {
    std::cout << "--- [Day 07: Templates & Standard Template Library] ---" << std::endl;

    // Test generic stack with strings
    SimpleStack<std::string> wordsStack;
    wordsStack.push("Modern");
    wordsStack.push("C++");
    wordsStack.push("Mastery");

    std::cout << "Popping from template stack: ";
    while (!wordsStack.empty()) {
        std::cout << wordsStack.pop() << " ";
    }
    std::cout << std::endl;

    // 2. STL Map & Frequency counter
    std::vector<std::string> fruits = {"apple", "banana", "apple", "orange", "banana", "apple"};
    std::unordered_map<std::string, int> fruitCounts;
    for (const auto& f : fruits) {
        fruitCounts[f]++;
    }

    std::cout << "\nFruit Frequencies (unordered_map):" << std::endl;
    for (const auto& [fruit, count] : fruitCounts) {
        std::cout << "  " << fruit << ": " << count << "\n";
    }

    // 3. STL Algorithms & Lambdas
    std::vector<int> numbers = {15, 3, 99, 42, 8, 23};
    std::sort(numbers.begin(), numbers.end());

    std::cout << "\nSorted numbers: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    int evenCount = std::count_if(numbers.begin(), numbers.end(), [](int n) {
        return n % 2 == 0;
    });
    std::cout << "Even number count: " << evenCount << std::endl;

    return 0;
}
