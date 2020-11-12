#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<ll> ars(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> ars[i];
    }

    vector<ll> delta(n, 0);
    for (int i = 0; i < q; i++) {
        int l, r, x, mi;
        cin >> l >> r >> x >> mi;
        if (mi > 5) continue;

        l--; r--;
        delta[l] += x;
        if (r + 1 < n) delta[r + 1] -= x;
    }

    ll atual = 0;
    for (int i = 0; i < n; i++) {
        atual += delta[i];
        ars[i] += atual;
    }

    for (int i = 0; i < n; i++) {
        cout << ars[i] << ' ';
    }
    cout << endl;

    return 0;
}