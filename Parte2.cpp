#include <map>
#include <string>

class Enviroment {
private:
    std::map<std::string, int> symbolTable;
public:
    void insert (const std::string &symbol, int value) {
        symbolTable[symbol] = value;
    }
};
int main () {
    Enviroment env;
    env.insert("symbol1", 1);
    env.insert("symbol2", 2);
    for (const auto& pair : env.symbolTable) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}
