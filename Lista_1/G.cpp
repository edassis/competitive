// Moedas infinitas
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a;

    cin >> n >> a;

    int aux = n % 500;
    aux = aux - a;

    if (aux > 0) {
        cout << "Nao" << endl;
    }
    else {
        cout << "Sim" << endl;
    }
    
    return 0;
}