# Day 08: Smart Pointers & RAII (Modern Memory Safety)

## Concepts Covered
- Resource Acquisition Is Initialization (RAII)
- `std::unique_ptr` (sole ownership, zero overhead, move-only)
- `std::shared_ptr` (shared ownership, reference counting)
- `std::weak_ptr` (non-owning reference, breaking cyclic graphs)
- Safe factory methods: `std::make_unique` and `std::make_shared`

## Exercise
Demonstrate automatic resource release when a custom resource class goes out of scope, and show reference count changes with `std::shared_ptr`.
