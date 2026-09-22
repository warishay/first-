# Modern C++ Mastery: Zero to Advanced Reference & Daily Submission Tracker

Welcome to the **Complete C++ Learning & Daily Practice Repository**. This repository contains an exhaustive conceptual guide to C++, practical coding examples covering every major topic, structured daily tasks, and automated scripts for daily GitHub submissions.

---

## Table of Contents
1. [C++ Architecture & Compilation Model](#1-c-architecture--compilation-model)
2. [Data Types, Variables & Type Modifiers](#2-data-types-variables--type-modifiers)
3. [Operators & Expressions](#3-operators--expressions)
4. [Control Flow: Conditionals & Loops](#4-control-flow-conditionals--loops)
5. [Functions, Overloading & Recursion](#5-functions-overloading--recursion)
6. [Arrays, C-Strings, and std::string](#6-arrays-c-strings-and-stdstring)
7. [Pointers, Memory Addresses & Dynamic Allocation](#7-pointers-memory-addresses--dynamic-allocation)
8. [Modern Smart Pointers & RAII](#8-modern-smart-pointers--raii)
9. [Object-Oriented Programming (OOP) Deep Dive](#9-object-oriented-programming-oop-deep-dive)
   - [Classes, Objects & Encapsulation](#classes-objects--encapsulation)
   - [Constructors, Destructors & Rule of Five](#constructors-destructors--rule-of-five)
   - [Inheritance & The Diamond Problem](#inheritance--the-diamond-problem)
   - [Polymorphism, Virtual Functions & VTables](#polymorphism-virtual-functions--vtables)
   - [Abstract Classes & Pure Virtual Functions](#abstract-classes--pure-virtual-functions)
10. [Operator Overloading](#10-operator-overloading)
11. [Templates & Generic Programming](#11-templates--generic-programming)
12. [Exception Handling](#12-exception-handling)
13. [File Handling & Streams (`<fstream>`)](#13-file-handling--streams-fstream)
14. [The Standard Template Library (STL)](#14-the-standard-template-library-stl)
15. [Modern C++ (C++11 to C++20) Features](#15-modern-c-c11-to-c20-features)
16. [Daily Task Roadmap & Checklist](#16-daily-task-roadmap--checklist)
17. [Daily GitHub Submission Workflow](#17-daily-github-submission-workflow)

---

## 1. C++ Architecture & Compilation Model

C++ is a compiled, statically typed, multi-paradigm language offering high-level abstractions with zero runtime overhead (zero-cost abstractions) and low-level memory access.

### Compilation Pipeline
When you compile a C++ file (e.g., `main.cpp`), the compiler runs four distinct stages:

```
[Source Code (.cpp / .h)] 
        │
        ▼ (1) Preprocessing (handles #include, #define, #ifdef)
[Expanded Source (.i)]
        │
        ▼ (2) Compilation (syntactic/semantic analysis -> Assembly)
[Assembly Code (.s)]
        │
        ▼ (3) Assembly (machine instructions)
[Object File (.o / .obj)]
        │
        ▼ (4) Linking (resolves symbols, merges standard libraries)
[Executable (.out / .exe)]
```

### Basic Program Template
```cpp
#include <iostream> // Preprocessor directive for input/output streams

int main() {
    // std::cout writes to standard output, std::endl flushes stream and inserts newline
    std::cout << "Hello, Modern C++ World!" << std::endl;
    return 0; // 0 indicates successful execution
}
```

---

## 2. Data Types, Variables & Type Modifiers

C++ provides strong static type checking and deterministic memory layout.

### Primitive Types and Sizes
| Type | Typical Size | Range / Description |
| :--- | :--- | :--- |
| `bool` | 1 byte | `true` (1) or `false` (0) |
| `char` | 1 byte | ASCII characters (`-128` to `127` or `0` to `255`) |
| `int` | 4 bytes | Integer values (`-2,147,483,648` to `2,147,483,647`) |
| `float` | 4 bytes | Single precision IEEE-754 (~7 decimal digits) |
| `double` | 8 bytes | Double precision IEEE-754 (~15-17 decimal digits) |
| `void` | 0 bytes | Absence of type |

### Type Modifiers
- `signed`, `unsigned` (e.g., `unsigned int count = 100u;`)
- `short`, `long`, `long long` (e.g., `long long bigNum = 9223372036854775807LL;`)

### Constant Qualifiers
- `const`: Evaluated at runtime or compile-time; cannot be modified after initialization.
- `constexpr`: Guaranteed to be computed at **compile-time**.

```cpp
constexpr int bufferSize = 1024 * 4; // Computed during compilation
const double pi = 3.141592653589793;
```

### Modern C++ Type Casting
Avoid C-style casts `(int)x`. Use type-safe modern casts:
- `static_cast<T>(v)`: Well-defined, compile-time checked conversions (e.g., float to int).
- `dynamic_cast<T>(v)`: Safely downcasts polymorphic class pointers/references using RTTI.
- `const_cast<T>(v)`: Adds or removes `const` or `volatile` qualifiers.
- `reinterpret_cast<T>(v)`: Low-level bit-pattern reinterpretation.

```cpp
double rawValue = 9.87;
int integerPart = static_cast<int>(rawValue);
```

---

## 3. Operators & Expressions

1. **Arithmetic**: `+`, `-`, `*`, `/`, `%`
2. **Relational**: `==`, `!=`, `<`, `>`, `<=`, `>=`
3. **Logical**: `&&` (AND), `||` (OR), `!` (NOT) - supports short-circuit evaluation.
4. **Bitwise**: `&` (AND), `|` (OR), `^` (XOR), `~` (NOT), `<<` (Left Shift), `>>` (Right Shift).
5. **Compound Assignment**: `+=`, `-=`, `*=`, `/=`, `%=`, `&=`, `|=`, `^=`.
6. **Ternary (Conditional)**: `condition ? value_if_true : value_if_false`.

---

## 4. Control Flow: Conditionals & Loops

### Decision Making
```cpp
int score = 85;
if (score >= 90) {
    std::cout << "Grade: A\n";
} else if (score >= 80) {
    std::cout << "Grade: B\n";
} else {
    std::cout << "Grade: C or below\n";
}

// Switch statement with integral/enum types
char grade = 'B';
switch (grade) {
    case 'A': std::cout << "Outstanding!\n"; break;
    case 'B': std::cout << "Good job!\n"; break;
    default:  std::cout << "Keep practicing!\n"; break;
}
```

### Loops
```cpp
// 1. While loop
int i = 0;
while (i < 5) { ++i; }

// 2. Do-while loop (guaranteed at least one execution)
int k = 0;
do {
    k++;
} while (k < 3);

// 3. Standard For loop
for (int j = 0; j < 5; ++j) {
    if (j == 2) continue; // Skip to next iteration
    if (j == 4) break;    // Terminate loop
}

// 4. Range-based For loop (C++11)
int arr[] = {10, 20, 30, 40};
for (const int& val : arr) {
    std::cout << val << " ";
}
```

---

## 5. Functions, Overloading & Recursion

### Pass-by-Value vs Pass-by-Reference vs Pass-by-Pointer
```cpp
// 1. Pass-by-Value (makes a copy, caller unaffected)
void incrementVal(int x) { x++; }

// 2. Pass-by-Reference (alias, modifies original, zero overhead)
void incrementRef(int& x) { x++; }

// 3. Pass-by-Const-Reference (read-only, no expensive copy for large objects)
void printName(const std::string& name) {
    std::cout << name << "\n";
}

// 4. Pass-by-Pointer (can be nullptr)
void resetPtr(int* ptr) {
    if (ptr) *ptr = 0;
}
```

### Function Overloading
Same function name with different parameter signatures:
```cpp
int multiply(int a, int b) { return a * b; }
double multiply(double a, double b) { return a * b; }
```

### Recursion
```cpp
unsigned long long factorial(unsigned int n) {
    if (n <= 1) return 1; // Base case
    return n * factorial(n - 1); // Recursive step
}
```

---

## 6. Arrays, C-Strings, and `std::string`

### Fixed-size Arrays vs `std::vector`
```cpp
// Static C-style array
int numbers[5] = {1, 2, 3, 4, 5};

// Modern dynamic string
#include <string>
std::string greeting = "Hello";
greeting += " C++";
std::cout << "Length: " << greeting.length() << "\n";
std::cout << "Substring: " << greeting.substr(0, 5) << "\n";
```

---

## 7. Pointers, Memory Addresses & Dynamic Allocation

A pointer stores the memory address of another variable.

```cpp
int val = 42;
int* ptr = &val; // & is address-of operator

std::cout << "Address: " << ptr << "\n";
std::cout << "Value via dereference: " << *ptr << "\n"; // * is dereference operator

*ptr = 100; // Modifies val directly
```

### Dynamic Memory Allocation (Heap)
- Allocating memory with `new` and releasing with `delete`:
```cpp
int* dynamicInt = new int(500); // Allocated on Heap
std::cout << *dynamicInt << "\n";
delete dynamicInt; // Prevent memory leak!
dynamicInt = nullptr; // Avoid dangling pointer!

// Dynamic Array
int* dynamicArr = new int[5]{1, 2, 3, 4, 5};
delete[] dynamicArr;
dynamicArr = nullptr;
```

---

## 8. Modern Smart Pointers & RAII

Modern C++ avoids manual `new`/`delete` using **RAII (Resource Acquisition Is Initialization)** and smart pointers from `<memory>`:

```cpp
#include <memory>

// 1. std::unique_ptr: Exclusive ownership (cannot be copied, can be moved)
std::unique_ptr<int> uPtr = std::make_unique<int>(100);

// 2. std::shared_ptr: Shared reference-counted ownership
std::shared_ptr<int> sPtr1 = std::make_shared<int>(200);
std::shared_ptr<int> sPtr2 = sPtr1; // Reference count becomes 2

// 3. std::weak_ptr: Non-owning observer that breaks circular references
std::weak_ptr<int> wPtr = sPtr1;
if (auto locked = wPtr.lock()) {
    std::cout << "Value: " << *locked << "\n";
}
```

---

## 9. Object-Oriented Programming (OOP) Deep Dive

### Classes, Objects & Encapsulation
```cpp
class BankAccount {
private:
    std::string owner;
    double balance;

public:
    // Parameterized Constructor with Member Initializer List
    BankAccount(std::string accOwner, double initialBalance)
        : owner(std::move(accOwner)), balance(initialBalance >= 0 ? initialBalance : 0.0) {}

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const { return balance; } // const member function
    const std::string& getOwner() const { return owner; }
};
```

### Constructors, Destructors & Rule of Five
When managing resources, implement or delete:
1. Destructor `~ClassName()`
2. Copy Constructor `ClassName(const ClassName&)`
3. Copy Assignment Operator `ClassName& operator=(const ClassName&)`
4. Move Constructor `ClassName(ClassName&&) noexcept`
5. Move Assignment Operator `ClassName& operator=(ClassName&&) noexcept`

### Inheritance & The Diamond Problem
```cpp
class Animal {
public:
    virtual void speak() const { std::cout << "Some generic sound\n"; }
    virtual ~Animal() = default; // Always make base destructors virtual!
};

class Dog : public Animal {
public:
    void speak() const override { std::cout << "Woof! Woof!\n"; }
};
```

To resolve the Diamond Problem in multiple inheritance, use `virtual` base classes:
```cpp
class Base { public: int id; };
class Left : virtual public Base {};
class Right : virtual public Base {};
class Bottom : public Left, public Right {}; // Contains only one instance of Base
```

### Polymorphism, Virtual Functions & VTables
Runtime polymorphism is implemented via a virtual method table (**vtable**) and virtual pointer (**vptr**):
```cpp
void makeSound(const Animal& animal) {
    animal.speak(); // Dynamically dispatched at runtime
}
```

### Abstract Classes & Pure Virtual Functions
A class with at least one pure virtual function (`= 0`) is abstract and acts as an interface:
```cpp
class IShape {
public:
    virtual ~IShape() = default;
    virtual double area() const = 0;       // Pure virtual function
    virtual double perimeter() const = 0;  // Pure virtual function
};
```

---

## 10. Operator Overloading

Allows custom behavior for operators on user-defined classes:
```cpp
class Complex {
public:
    double real, imag;
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload binary '+'
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload stream extraction '<<'
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
};
```

---

## 11. Templates & Generic Programming

Write code that works with any data type.

```cpp
// Function Template
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// Class Template
template <typename T, size_t Capacity>
class StaticStack {
private:
    T data[Capacity];
    size_t topIndex = 0;
public:
    void push(const T& item) {
        if (topIndex < Capacity) data[topIndex++] = item;
    }
    T pop() { return data[--topIndex]; }
    bool isEmpty() const { return topIndex == 0; }
};
```

---

## 12. Exception Handling

Robust error management separating detection from recovery:
```cpp
#include <stdexcept>

double safeDivide(double num, double den) {
    if (den == 0.0) {
        throw std::invalid_argument("Division by zero error!");
    }
    return num / den;
}

int main() {
    try {
        double result = safeDivide(10.0, 0.0);
        std::cout << result << "\n";
    } catch (const std::invalid_argument& ex) {
        std::cerr << "Caught exception: " << ex.what() << "\n";
    }
}
```

---

## 13. File Handling & Streams (`<fstream>`)

```cpp
#include <fstream>
#include <string>

// Writing to file
std::ofstream outFile("data.txt");
if (outFile.is_open()) {
    outFile << "Line 1: Storing C++ data\n";
    outFile << "Line 2: Modern C++ file streams\n";
    outFile.close();
}

// Reading line-by-line
std::ifstream inFile("data.txt");
std::string line;
while (std::getline(inFile, line)) {
    std::cout << line << "\n";
}
```

---

## 14. The Standard Template Library (STL)

The STL consists of **Containers**, **Iterators**, and **Algorithms**:

```cpp
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

int main() {
    std::vector<int> nums = {5, 2, 8, 1, 9, 3};

    // Sort algorithm (O(N log N))
    std::sort(nums.begin(), nums.end());

    // Binary search
    bool exists = std::binary_search(nums.begin(), nums.end(), 8);

    // Accumulate sum
    int total = std::accumulate(nums.begin(), nums.end(), 0);

    // Transform with Lambda
    std::transform(nums.begin(), nums.end(), nums.begin(), [](int n) { return n * 2; });
}
```

### Essential STL Containers
- `std::vector`: Dynamic contiguous array (fast random access $O(1)$, push_back amortized $O(1)$).
- `std::list`: Doubly linked list (fast insertions anywhere $O(1)$).
- `std::map`: Self-balancing Red-Black tree ($O(\log N)$ search/insert).
- `std::unordered_map`: Hash table ($O(1)$ average search/insert).
- `std::stack`, `std::queue`, `std::priority_queue`: Container adaptors.

---

## 15. Modern C++ (C++11 to C++20) Features

- **Type Deduction**: `auto x = 42;`, `decltype(expr)`
- **Lambdas**: `[capture](params) -> return_type { body }`
- **Move Semantics & Rvalues**: `std::move()`, preventing costly deep copies of dynamic buffers.
- **Nullptr**: Type-safe replacement for `NULL` or `0`.
- **Structured Bindings (C++17)**: `auto [key, val] = pair;`

---

## 16. Daily Task Roadmap & Checklist

Track your daily learning and GitHub submissions here:

| Day | Topic | Key Concepts | Status |
| :---: | :--- | :--- | :---: |
| **Day 01** | C++ Basics & I/O | Data types, streams, syntax, variables | [ ] Pending |
| **Day 02** | Control Flow & Logic | Conditionals, switch, while, for loops | [ ] Pending |
| **Day 03** | Functions & Modularity | Pass-by-ref, overloading, recursion | [ ] Pending |
| **Day 04** | Pointers & Memory | Addresses, dereferencing, heap allocation | [ ] Pending |
| **Day 05** | OOP Foundations | Classes, encapsulation, constructors | [ ] Pending |
| **Day 06** | Inheritance & Polymorphism | Virtual functions, abstract classes, VTable | [ ] Pending |
| **Day 07** | Templates & STL | Generic algorithms, vectors, maps, iterators | [ ] Pending |
| **Day 08** | Smart Pointers & RAII | `unique_ptr`, `shared_ptr`, memory safety | [ ] Pending |
| **Day 09** | Operator Overloading | Custom math types, stream operators `<<` / `>>` | [ ] Pending |
| **Day 10** | File I/O & Streams | Text & binary file streams, serialization | [ ] Pending |
| **Day 11** | Exception Handling | Robust validation, custom exceptions | [ ] Pending |
| **Day 12** | Move Semantics & Rvalues | Rvalue refs (`&&`), move constructors, RAII | [ ] Pending |

---

## 17. Daily GitHub Submission Workflow

Follow this step-by-step workflow every day to submit your daily task to GitHub:

### Step 1: Compile & Test Your Code
Compile your daily C++ code using `g++` or `clang++`:
```bash
clang++ -std=c++17 -Wall -Wextra main.cpp -o main
./main
```

### Step 2: Check Git Status
Check the files you modified or created:
```bash
git status
```

### Step 3: Stage, Commit & Push to GitHub
Submit your daily task directly to GitHub:
```bash
git add .
git commit -m "Day 01: Completed C++ Basics and I/O tasks"
git push origin main
```

---
*Happy Coding & C++ Mastery!*

