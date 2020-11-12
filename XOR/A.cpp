#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

ll DecimalToBinary(ll n) {
    vector<ll> bin;
    
    while (n > 0) {
        bin.pb(n % 2);
        n = n / 2;
    }

    ll res = 0;
    for (int i = (int)bin.size() - 1; i >= 0; i--) {
        res = res * 10 + bin[i];
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b;
    cin >> a >> b;

    cout << (a ^ b) << endl;

    return 0;
}