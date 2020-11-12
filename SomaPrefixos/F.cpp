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
    vi vet(n);
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    vector<ll> psum(n);
    psum[0] = vet[0];
    for (int i = 1; i < n; i++) {
        psum[i] = vet[i] ^ psum[i-1];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l-1 >= 0)
            cout << (psum[r] ^ psum[l-1]) << endl;
        else
            cout << psum[r] << endl;
    }

    return 0;
}