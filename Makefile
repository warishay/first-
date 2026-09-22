CXX := clang++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -O2

DAYS := day01_basics day02_control_flow day03_functions day04_pointers_memory day05_oop_classes day06_inheritance_polymorphism day07_templates_stl day08_smart_pointers_raii

.PHONY: all clean run-all $(DAYS)

all: $(DAYS)

day01_basics:
	@mkdir -p tasks/day01_basics/bin
	$(CXX) $(CXXFLAGS) tasks/day01_basics/main.cpp -o tasks/day01_basics/bin/task

day02_control_flow:
	@mkdir -p tasks/day02_control_flow/bin
	$(CXX) $(CXXFLAGS) tasks/day02_control_flow/main.cpp -o tasks/day02_control_flow/bin/task

day03_functions:
	@mkdir -p tasks/day03_functions/bin
	$(CXX) $(CXXFLAGS) tasks/day03_functions/main.cpp -o tasks/day03_functions/bin/task

day04_pointers_memory:
	@mkdir -p tasks/day04_pointers_memory/bin
	$(CXX) $(CXXFLAGS) tasks/day04_pointers_memory/main.cpp -o tasks/day04_pointers_memory/bin/task

day05_oop_classes:
	@mkdir -p tasks/day05_oop_classes/bin
	$(CXX) $(CXXFLAGS) tasks/day05_oop_classes/main.cpp -o tasks/day05_oop_classes/bin/task

day06_inheritance_polymorphism:
	@mkdir -p tasks/day06_inheritance_polymorphism/bin
	$(CXX) $(CXXFLAGS) tasks/day06_inheritance_polymorphism/main.cpp -o tasks/day06_inheritance_polymorphism/bin/task

day07_templates_stl:
	@mkdir -p tasks/day07_templates_stl/bin
	$(CXX) $(CXXFLAGS) tasks/day07_templates_stl/main.cpp -o tasks/day07_templates_stl/bin/task

day08_smart_pointers_raii:
	@mkdir -p tasks/day08_smart_pointers_raii/bin
	$(CXX) $(CXXFLAGS) tasks/day08_smart_pointers_raii/main.cpp -o tasks/day08_smart_pointers_raii/bin/task

run-all: all
	@echo "=========================================="
	@echo "▶ Running Day 01: Basics"
	@./tasks/day01_basics/bin/task
	@echo "\n▶ Running Day 02: Control Flow"
	@./tasks/day02_control_flow/bin/task
	@echo "\n▶ Running Day 03: Functions"
	@./tasks/day03_functions/bin/task
	@echo "\n▶ Running Day 04: Pointers & Memory"
	@./tasks/day04_pointers_memory/bin/task
	@echo "\n▶ Running Day 05: OOP Classes"
	@./tasks/day05_oop_classes/bin/task
	@echo "\n▶ Running Day 06: Inheritance & Polymorphism"
	@./tasks/day06_inheritance_polymorphism/bin/task
	@echo "\n▶ Running Day 07: Templates & STL"
	@./tasks/day07_templates_stl/bin/task
	@echo "\n▶ Running Day 08: Smart Pointers & RAII"
	@./tasks/day08_smart_pointers_raii/bin/task
	@echo "\n=========================================="
	@echo "✓ All tasks executed successfully!"

clean:
	rm -rf tasks/**/bin/ *.dSYM
