#include <iostream>
#include <map>
#include <string>

class Enviroment {
private:
    std::map<std::string, int> symbolTable;
public:
    void insert(const std::string& symbol, int value) {
        symbolTable[symbol] = value;
    }

    std::map<std::string, int> getSymbolTable() const {
        return symbolTable;
    }
};
int main () {
    Enviroment env;
    env.insert("symbol1", 1);
    env.insert("symbol2", 2);
    std::map<std::string, int> symbolTable = env.getSymbolTable();
    for (const auto& pair : symbolTable) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}
