# Day 06: Inheritance, Virtual Functions & Polymorphism

## Concepts Covered
- Base classes and derived classes
- Access specifier `protected`
- Virtual functions and runtime dispatch (vtable / vptr)
- Abstract classes and pure virtual functions (`= 0`)
- The `override` and `final` specifiers
- Virtual destructors (preventing resource leaks when deleting via base pointer)

## Exercise
Create an abstract `Employee` hierarchy (`FullTimeEmployee`, `Contractor`) and dynamically calculate payroll through polymorphic base pointers.
