#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>


// bool p_sort(ii &a, ii &b) {
//     return a.first < b.first;
// }

int main() {
    ll n, s;

    cin >> n >> s;
    vector<ll> item(n);

    for (unsigned i = 0; i < n; i++) {
        cin >> item[i];
    }

    // sort(item.begin(), item.end(), p_sort);

    ll l = 1, r = n;
    ll res = -1;
    ll valor = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;  // k

        ll valor_aux = 0;
        vector<ll> preco(n);
        
        for (unsigned i = 0; i < item.size(); i++) {
            ll aux = item[i] + (i + 1) * mid;
            preco[i] = aux;
        }

        sort(preco.begin(), preco.end());

        for (int i = 0; i < mid; i++) {
            valor_aux += preco[i];
        }

        if (valor_aux <= s) {
            res = mid;
            valor = valor_aux;
            
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if (res != -1) cout << res << " " << valor << endl;
    else cout << "0 0" << endl;

    return 0;
}