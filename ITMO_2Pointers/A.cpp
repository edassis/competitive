#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" \
                  << "\n";
#else
#define W(x)
#endif

using namespace std;

#define vi  vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define ll  long long
#define pb  push_back
#define eb  emplace_back
#define mp  make_pair
#define ii  pair<int, int>
#define ff  first
#define ss  second

#define prime 1e9 + 7

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    ll s; cin >> s;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 0, ans = 0;
    ll x = 0;
    for (r = 0; r < n; r++) {
        x += a[r];

        while (x > s) {
            x -= a[l];
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans << endl;

    return 0;
}