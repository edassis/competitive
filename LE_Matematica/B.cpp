#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

#define PRIMO 1000000007

ll fat (ll n) {
    if (n < 1) {
        return 1;
    }

    return (n * fat(n-1)) % PRIMO;
}

ll fat2(ll n) {
    ll ans = 1;
    for (ll i = 1; i <= n; i++) {
        ans = (ans*i) % PRIMO;
    }

    return ans;
}

vector<ll> fat_until_n(ll n) {
    vector<ll> res;
    ll aux = 1;
    res.pb(1);

    for (int i = 1; i <= n; i++) {
        aux = aux * i % PRIMO;
        res.pb(aux);
    }

    return res;
}

int main() {
    int q;
    scanf("%d", &q);

    vector<ll> res = fat_until_n(1000000);

    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);

        printf("%lld\n", res[x]);
    }

    return 0;
}