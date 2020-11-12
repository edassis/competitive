#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

vi crivo(int n) {
    vector<bool> ehprimo(n+1, true);
    vi primo;

    ehprimo[0] = false;
    ehprimo[1] = false;
    primo.pb(2);
    for (int i = 3; i <= n; i += 2) {
        ehprimo[i+1] = false;
        if (ehprimo[i]) {
            primo.pb(i);
            
            for (int j = i+i; j <= n; j += i) {
                ehprimo[j] = false;
            }
        }
    }

    // contabilizar qtd de primos
    int contador = 0;
    vi qtd_primos(n+1, 0);
    for (int i = 0; i <= n; i++) {
        if (ehprimo[i]) {
            contador++;
        }

        qtd_primos[i] = contador;
    }

    return qtd_primos;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    scanf("%d\n", &q);

    vi qtd_primos = crivo(1000000);

    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        printf("%d\n", qtd_primos[r] - qtd_primos[l - 1]);
    }

    return 0;
}