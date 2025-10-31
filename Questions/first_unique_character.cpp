#include <iostream>
#include <unordered_map>
#include <string>

int firstUniqueChar(const std::string& s) {
    std::unordered_map<char, int> count;
    
    //Contar ocurrencias
    for(char c : s) {
        count[c]++;
    }

    //Buscar el primer caracter unico
    for(size_t i = 0; i < s.size(); ++i) {
        if(count[s[i]] == 1) {
            return static_cast<int>(i);
        }
    }
    return -1;
}