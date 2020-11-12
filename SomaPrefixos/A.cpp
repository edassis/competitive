#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int n, q;

    cin >> n >> q;
    vi vetor(n);

    for (int i = 0; i < n; i++) {
        cin >> vetor[i];
    }

    vector<ll> psum(n);
    ll atual = 0;
    for (int i = 0; i < n; i++) {
        atual += vetor[i];
        psum[i]	= atual;
    }
    
    for (int i = 0; i < q; i++) {
        int l, r;
        ll res;
        cin >> l >> r;
        l--;
        r--;
        if (l == 0)
            res = psum[r];
        else
            res = psum[r] - psum[l-1];

        cout << res << endl;
    }
    
    return 0;
}