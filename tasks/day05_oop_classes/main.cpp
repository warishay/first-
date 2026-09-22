#include <iostream>
#include <string>
#include <iomanip>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    // Parameterized Constructor using Member Initializer List
    BankAccount(std::string accNum, std::string holder, double initialDeposit)
        : accountNumber(std::move(accNum)),
          accountHolder(std::move(holder)),
          balance(initialDeposit >= 0.0 ? initialDeposit : 0.0) {
        std::cout << "[LOG] Created account #" << accountNumber << " for " << accountHolder << "\n";
    }

    // Destructor
    ~BankAccount() {
        std::cout << "[LOG] Closed account #" << accountNumber << "\n";
    }

    void deposit(double amount) {
        if (amount > 0.0) {
            balance += amount;
            std::cout << "Deposited $" << amount << ". New Balance: $" << balance << "\n";
        }
    }

    bool withdraw(double amount) {
        if (amount > 0.0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrew $" << amount << ". Remaining Balance: $" << balance << "\n";
            return true;
        }
        std::cout << "Withdrawal of $" << amount << " declined (Insufficient funds or invalid amount).\n";
        return false;
    }

    // Const member functions guaranteeing no mutation
    double getBalance() const { return balance; }
    const std::string& getHolder() const { return accountHolder; }
    const std::string& getAccountNumber() const { return accountNumber; }
};

int main() {
    std::cout << "--- [Day 05: OOP Classes & Encapsulation] ---" << std::endl;
    std::cout << std::fixed << std::setprecision(2);

    {
        BankAccount account("ACC-98765", "Alice Smith", 500.00);
        account.deposit(250.50);
        account.withdraw(120.00);
        account.withdraw(1000.00); // Should fail safely
        std::cout << "Final balance for " << account.getHolder() << ": $" << account.getBalance() << "\n";
    } // account goes out of scope here and destructor is automatically called

    return 0;
}
