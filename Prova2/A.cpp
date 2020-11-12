#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>

ll all_divisors(ll n) {
    vll res;

    for (ll x = 1; x*x <= n; x++) {
        if (n % x == 0) {
            ll b = n / x;
            res.eb(x);
            if (x != b) res.eb(b);
        }
    }

    return res.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (all_divisors(n) % 2 == 0) {
        cout << "desligada" << endl;
    } else {
        cout << "ligada" << endl;
    }
    
    return 0;
}