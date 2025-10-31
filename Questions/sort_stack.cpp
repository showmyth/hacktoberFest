#include <iostream>
#include <stack>

//Inserta un elemento en la posicion correcta dentro de una pila ordenada
void insertSorted(std::stack<int>& s, int val) {
    if (s.empty() || val > s.top()) {
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();
    insertSorted(s, val);
    s.push(temp);
}
    //Ordena la pila usando recursion
    void sortStack(std::stack<int>& s) {
        if(!s.empty()){
            int temp = s.top();
            s.pop();
            sortStack(s);
            insertSorted(s,temp);
        }
    }
