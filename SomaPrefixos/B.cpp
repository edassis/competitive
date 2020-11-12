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

    vector<ll> vet(n);
    vi delta(n);
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;
        
        delta[l] += x;
        if (r+1 < n)
            delta[r+1] -= x; 
    }

    vet[0] = delta[0];
    cout << vet[0] << ' ';
    for (int i = 1; i < n; i++) {
        vet[i] = delta[i] + vet[i-1];
        cout << vet[i] << ' ';
    }
    cout << endl;

    return 0;
}