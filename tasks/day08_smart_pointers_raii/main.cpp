#include <iostream>
#include <memory>
#include <string>

class DatabaseConnection {
private:
    std::string connectionName;

public:
    explicit DatabaseConnection(std::string name) : connectionName(std::move(name)) {
        std::cout << "[CONNECTED] Opened connection: " << connectionName << "\n";
    }

    ~DatabaseConnection() {
        std::cout << "[DISCONNECTED] Automatically closed connection: " << connectionName << "\n";
    }

    void executeQuery(const std::string& sql) const {
        std::cout << "  -> (" << connectionName << ") Executing: " << sql << "\n";
    }
};

int main() {
    std::cout << "--- [Day 08: Smart Pointers & RAII] ---" << std::endl;

    // 1. std::unique_ptr (Exclusive ownership)
    std::cout << "\n1. Testing std::unique_ptr:\n";
    {
        auto db1 = std::make_unique<DatabaseConnection>("Primary_Postgres");
        db1->executeQuery("SELECT * FROM users WHERE active = true;");
        // db1 is automatically destroyed and memory reclaimed here at closing brace
    }

    // 2. std::shared_ptr (Reference counted ownership)
    std::cout << "\n2. Testing std::shared_ptr:\n";
    std::shared_ptr<DatabaseConnection> sharedRef1;
    {
        auto db2 = std::make_shared<DatabaseConnection>("Analytics_Replica");
        std::cout << "Current use_count: " << db2.use_count() << "\n";

        sharedRef1 = db2; // Share ownership
        std::cout << "After assigning to sharedRef1, use_count: " << db2.use_count() << "\n";

        sharedRef1->executeQuery("SELECT COUNT(*) FROM events;");
    } // db2 goes out of scope, but connection is kept alive because sharedRef1 still holds it

    std::cout << "Outside inner block, sharedRef1 use_count: " << sharedRef1.use_count() << "\n";
    sharedRef1->executeQuery("SELECT AVG(duration) FROM sessions;");

    sharedRef1.reset(); // Manually release or allow to go out of scope
    std::cout << "Smart pointers ensure ZERO memory leaks!\n";

    return 0;
}
