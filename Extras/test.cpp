#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;

    s.insert(3); // insere elemento no set
    cout << s.size() << endl; // tamanho do set

    // para verificar se um elemento está contido no set ou nao podemos utilizar
    // o metodo find; caso nao esteja presente ele retornará o iterator para
    // o fim do set

    if(s.find(2) == s.end()) {
        cout << "O numero 2 nao esta no set" << endl;
    }
    else {
        cout << "O numero 2 esta no set" << endl;
    }

    if(s.find(3) == s.end()) {
        cout << "O numero 3 nao esta no set" << endl;
    }
    else {
        cout << "O numero 3 esta no set" << endl;
    }
    
    s.erase(3); // apaga elemento 3 do set
    
    if(s.find(3) == s.end()) {
        cout << "O numero 3 nao esta no set" << endl;
    }
    else {
        cout << "O numero 3 esta no set" << endl;
    }

    return 0;
}