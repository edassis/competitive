#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>

vll all_divisors(ll n) {
    vll res;

    for (ll x = 1; x*x <= n; x++) {
        if (n % x == 0) {
            ll b = n / x;
            res.eb(x);
            if (x != b) res.eb(b);
        }
    }

    sort(res.begin(), res.end());
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vll divs = all_divisors(n);
    divs.pop_back();

    ll aux = 0;
    for (auto &e : divs) {
        aux += e;
    }
    
    if (aux == n) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}