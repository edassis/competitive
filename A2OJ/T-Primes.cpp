#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int, int>
#define ff first
#define ss second

#define PRIMO 1000000007

vi crivo_lp(ll n) {
    vi lp(n + 1, -1);

    for (ll i = 2; i <= n; i++) {
        if (lp[i] == -1) {
            for (ll j = i; j <= n; j += i) {
                lp[j] = i;
            }
        }
    }

    return lp;
}

vii fatora(ll n, vi &lp) {
    map<int, int> expoentes;

    while (n > 1) {
        expoentes[lp[n]]++;
        n /= lp[n];
    }

    vii ans;
    for (auto e : expoentes) {
        ans.eb(e);
    }

    return ans;
}

vi sieve(ll n) {
    vi prime;
    prime.pb(2);
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (ll i = 3; i <= n; i += 2) {
        is_prime[i + 1] = false;

        if (is_prime[i]) {
            prime.eb(i);
            for (ll j = i + i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return prime;
}

vi computa_div(ll n) {
    vi qtd_div(n + 1);

    for (ll i = 1; i <= n; i++) {
        for (ll j = i; j <= n; j++) {
            qtd_div[j]++;
        }
    }

    return qtd_div;
}

vll divisors(ll n) {
    vll div;

    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ll quo = n / i;
            div.pb(i);
            if (i != quo) div.pb(quo);
        }
    }
    sort(div.begin(), div.end());

    return div;
}

ll floorSqrt(ll n) {
    if (n == 1 || n == 0) return n;

    ll i = 1, result = 1;
    while (result <= n) {
        i++;
        result = i * i;
    }

    return i - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vi prime = sieve(floorSqrt(1e12));
    set<ll> primet;

    for (ll e : prime) {
        primet.emplace(e*e);
    }

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;

        if (primet.count(x))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}