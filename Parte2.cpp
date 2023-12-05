#include <iostream>
#include <map>
#include <string>

class Enviroment {
private:
    std::map<std::string, int> symbolTable;
public:
    void insert(const std::string& symbol, int value) {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end() && it->second != value) {
            throw std::runtime_error("Symbol already exists");
    }
        symbolTable[symbol] = value;
    }
    int lookup(const std::string& symbol) const {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            throw std::runtime_error("Symbol not found");
        }
    }
    std::map<std::string, int> getSymbolTable() const {
        return symbolTable;
    }
};
int main () {
    Enviroment env;
    try {
        env.insert("symbol1", 1);
        env.insert("symbol2", 2);
        env.insert("symbol1", 3);
        int value = env.lookup("symbol1");
        std::cout << "Valor de symbol1: " << value << std::endl;
        value = env.lookup("symbol3");
        std::cout << "Valor de symbol3: " << value << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
