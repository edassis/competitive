#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main() {
    int n, m;
    cin >> n >> m;
    
    n++;
    vi pedras(n);

    for (int i = 1; i < n; i++) {
        cin >> pedras[i];
    }

    vi ord_pedras = pedras;
    sort(ord_pedras.begin(), ord_pedras.end());

    vector<ll> psum(n, 0);
    vector<ll> ord_psum(n, 0);
    for(int i = 1; i < n; i++) {
        psum[i] = psum[i - 1] + pedras[i];
        ord_psum[i] = ord_psum[i - 1] + ord_pedras[i];
    }

    for (int i = 0; i < m; i++) {
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1) {
            cout << psum[r] - psum[l - 1] << endl;
        } else {
            cout << ord_psum[r] - ord_psum[l - 1] << endl;
        }
    }
    return 0;
}