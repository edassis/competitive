#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi v(n);
    ll n_soma = 0;
    ll n_xor = 0;
    vector<ll> comp;

    for (int i = 0; i<n; i++) {
        cin >> v[i];
        n_soma += v[i];
        n_xor ^= v[i];
    }

    n_xor *= 2;
    if (n_xor == n_soma) {
        cout << 0 << endl << endl;
        return 0;
    }

    ll aux = n_xor/2;
    if (aux) comp.pb(aux);
    aux = n_soma + n_xor/2;
    if (aux) comp.pb(aux);
    
    cout << comp.size() << endl;
    for (auto& e:comp) {
        cout << e << ' ';
    }
    cout << endl;

    return 0;
}