#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int n;
    cin >> n;

    vector<bool> ehprimo(n+1, true);
    ehprimo[0] = false;
    ehprimo[1] = false;

    vi primos;
    primos.pb(2);

    for (int i = 3; i <= n; i+=2) {
        ehprimo[i + 1] = false;
        if (ehprimo[i]) {
            primos.pb(i);
            for (int j = i+i; j <= n; j += i) {
                ehprimo[j] = false;
            }
        }
    }

    int qtd = 0;
    for (int i = 1; i <= n; i++) {
        int aux = 0;
        for (auto &e:primos) {
            if (i % e == 0) {
                aux++;
            }
        }
        if (aux == 2) qtd++;
    }

    cout << qtd << endl;

    return 0;
}