#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>

vector<pair<ll, ll>> fatora(ll n) {
    vector<pair<ll, ll>> ans;

    for (ll x = 2; x*x <= n; x++) {
        ll exp = 0;
        while (n % x == 0) {
            n /= x;
            exp++;
        }
        if (exp) ans.pb({x, exp}); 
    }
    if (n > 1) ans.pb({n, 1});

    return ans;
}

bool ehprimo(ll n) {
    if (n == 1) return false;

    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<pair<ll, ll>> fatores = fatora(n);

    int aux = 1;
    if (!fatores.empty()) aux--;

    for (auto &e : fatores) {
        aux += e.first + e.second;
    }

    if (ehprimo(aux)) {
        printf("%d\n", aux);
    } else {
        printf("-1\n");
    }

    return 0;
}