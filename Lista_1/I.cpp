// Treinamento
#include <bits/stdc++.h>

using namespace std;

void ordena_vetor(vector<int>& v) {
    for (int i = 0; i < (int)v.size() - 1; i++) {
        for (int j = i + 1; j < (int)v.size(); j++) {
            if (v[i] > v[j]) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main() {
    int n;
    
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());

    // int dia = 0;
    int contador = 1;
    
    for (int i = 0; i < n; i++) {
        if (a[i] >= contador) {
            // dia++;
            contador++;
        }
    }

    cout << contador - 1 << endl;

    return 0;
}