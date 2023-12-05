#include <iostream>
#include <map>
#include <string>
#include <variant>

using Symbol = std::variant<int, float, std::string>;

class Enviroment {
private:
    std::map<std::string, Symbol> symbolTable;
public:
    void insert(const std::string& symbol, Symbol value) {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end() && it->second != value) {
            throw std::runtime_error("Symbol ya existe");
        }
        symbolTable[symbol] = value;
    }
    Symbol lookup(const std::string& symbol) const {
        auto it = symbolTable.find(symbol);
        if (it == symbolTable.end()) {
            return it->second;
        } else {
            throw std::runtime_error("Symbol no existe");
        }
    }
    std::map<std::string, Symbol> getSymbolTable() const {
        return symbolTable;
    }
};
int main () {
    Enviroment env;
    try {
        env.insert("symbol1", 1);
        env.insert("symbol2", 2.0f);
        env.insert("symbol3", "hola");
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        Symbol value = env.lookup("symbol1");
        std::visit([](auto&& arg) {
            std::cout << "Valor de symbol1: " << arg << std::endl;
        }, value);
    } catch (const std::runtime_error &e ) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        Symbol value = env.lookup("symbol2");
        std::visit([](auto&& arg) {
            std::cout << "Valor de symbol2: " << arg << std::endl;
        }, value);
    } catch (const std::runtime_error &e ) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        Symbol value = env.lookup("symbol3");
        std::visit([](auto&& arg) {
            std::cout << "Valor de symbol3: " << arg << std::endl;
        }, value);
    } catch (const std::runtime_error &e ) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
