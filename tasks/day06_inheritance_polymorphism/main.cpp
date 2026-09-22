#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>

// Abstract Base Class (Interface)
class Employee {
protected:
    std::string name;
    int id;

public:
    Employee(std::string empName, int empId) : name(std::move(empName)), id(empId) {}

    // Pure virtual function
    virtual double calculateMonthlyPay() const = 0;

    virtual void displayInfo() const {
        std::cout << "ID: " << id << " | Name: " << name;
    }

    // Crucial: Virtual destructor prevents undefined behavior when deleting derived objects via base pointers
    virtual ~Employee() = default;
};

// Derived Class 1: Full-Time Employee
class FullTimeEmployee : public Employee {
private:
    double annualSalary;

public:
    FullTimeEmployee(std::string empName, int empId, double salary)
        : Employee(std::move(empName), empId), annualSalary(salary) {}

    double calculateMonthlyPay() const override {
        return annualSalary / 12.0;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << " | Type: Full-Time | Monthly Pay: $" << calculateMonthlyPay() << "\n";
    }
};

// Derived Class 2: Contractor
class Contractor : public Employee {
private:
    double hourlyRate;
    double hoursWorked;

public:
    Contractor(std::string empName, int empId, double rate, double hours)
        : Employee(std::move(empName), empId), hourlyRate(rate), hoursWorked(hours) {}

    double calculateMonthlyPay() const override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << " | Type: Contractor | Monthly Pay: $" << calculateMonthlyPay() << "\n";
    }
};

int main() {
    std::cout << "--- [Day 06: Inheritance & Polymorphism] ---" << std::endl;
    std::cout << std::fixed << std::setprecision(2);

    // Dynamic polymorphism using base pointers
    std::vector<std::unique_ptr<Employee>> staff;
    staff.push_back(std::make_unique<FullTimeEmployee>("Diana Prince", 101, 96000.00));
    staff.push_back(std::make_unique<Contractor>("Bruce Wayne", 102, 120.00, 160));
    staff.push_back(std::make_unique<Contractor>("Clark Kent", 103, 45.00, 80));

    double totalPayroll = 0.0;
    for (const auto& emp : staff) {
        emp->displayInfo(); // Dispatched at runtime via vtable
        totalPayroll += emp->calculateMonthlyPay();
    }

    std::cout << "--------------------------------------------\n";
    std::cout << "Total Company Monthly Payroll: $" << totalPayroll << "\n";

    return 0;
}
