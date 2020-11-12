#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k1, k2;
    vector<long long> a, b;

    cin >> n >> k1 >> k2;

    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        a.push_back(aux);
    }
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        b.push_back(aux);
    }

    int maior_idx = 0;
    long long maior = 0;
    while (k1 || k2) {
        for (int i = 0; i < n; i++) {
            if (abs(a[i] - b[i]) > maior || i == 0) {
                maior = abs(a[i] - b[i]);
                maior_idx = i;
            }
        }

        if (k1) {
            if (a[maior_idx] >= b[maior_idx]) {
                a[maior_idx]--;
                k1--;
            } else {
                a[maior_idx]++;
                k1--;
            }
        } else if (k2) {
            if (a[maior_idx] <= b[maior_idx]) {
                b[maior_idx]--;
                k2--;
            } else {
                b[maior_idx]++;
                k2--;
            }
        }
    }
    
    long long soma = 0;
    for (int i = 0; i < n; i++) {
        soma += (a[i] - b[i]) * (a[i] - b[i]);
    }
    
    cout << soma << endl;
    
    return 0;
}