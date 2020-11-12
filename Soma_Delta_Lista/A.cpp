// A. Plantio de Café
#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int n, q, t;
    cin >> n >> q >> t;

    vector<ll> delta(n+1, 0);
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        delta[l] += x;
        if (r + 1 <= n) delta[r+1] -= x;
    }

    vector<ll> lote(n+1, 0);
    ll atual = delta[0];
    for (int i = 1; i <= n; i++) {
        atual += delta[i];
        lote[i] = atual;
    }

    int cont = 0;
    for (int i = 0; i <= n; i++) {
        if (lote[i] >= t) cont++;
    }

    cout << cont << endl;

    return 0;
}