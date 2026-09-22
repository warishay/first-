#include <iostream>
#include <vector>

int main() {
    std::cout << "--- [Day 02: Control Flow & Loops] ---" << std::endl;

    // 1. Switch Statement
    int score = 88;
    char gradeCategory = (score >= 90) ? 'A' : (score >= 80) ? 'B' : (score >= 70) ? 'C' : 'F';
    
    std::cout << "Score: " << score << " -> Classification: ";
    switch (gradeCategory) {
        case 'A': std::cout << "Grade A (Distinction)\n"; break;
        case 'B': std::cout << "Grade B (Merit)\n"; break;
        case 'C': std::cout << "Grade C (Pass)\n"; break;
        default:  std::cout << "Failing Grade\n"; break;
    }

    // 2. Fibonacci Generation using for-loop
    int terms = 10;
    long long t1 = 0, t2 = 1;
    std::cout << "First " << terms << " Fibonacci numbers: ";
    for (int i = 1; i <= terms; ++i) {
        std::cout << t1 << (i == terms ? "" : ", ");
        long long nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    std::cout << "\n";

    // 3. Prime Number check
    int checkNum = 29;
    bool isPrime = (checkNum > 1);
    for (int i = 2; i * i <= checkNum; ++i) {
        if (checkNum % i == 0) {
            isPrime = false;
            break;
        }
    }
    std::cout << "Is " << checkNum << " prime? " << (isPrime ? "Yes" : "No") << std::endl;

    return 0;
}
