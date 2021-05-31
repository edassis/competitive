#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
#else
    #define W(x)
#endif

using namespace std;

#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>
#define ff first
#define ss second

#define prime 1e9+7

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    vi l(n);
    for(int i = 0; i < n; i++) cin >> l[i];

    while(q--) {
        int r; cin >> r;
        if (r == 1) {
            int i, x; cin >> i >> x;
            l[i] = x;
        } else {
            // maior produto de dois elementos distintos do subarray
        }
    }
    return 0;
}