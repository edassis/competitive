#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int, int>

#define MAX 1000000000000

vector<ll> crivo(ll n) {
    // vector<ll> lp(n + 1, -1);
    vector<bool> ehprimo(n+1, true);
    vector<ll> primos;

    ehprimo[1] = false;
    primos.eb(2);
    primos.eb(3);
    for (ll i = 3; i <= n; i+=2) {
        // if (lp[i] == -1) {
        //     for (ll j = i; j <= n; j += i) {
        //         lp[j] = i;  // biggest prime divisor
        //     }
            // primos.pb(i);
        // }
        ehprimo[i+1] = false;
        if (ehprimo[i]) {
            primos.eb(i);

            for (int x = i+i; x <= n; x+=i) { 
                ehprimo[x] = false;
            }
        }
    }

    return primos;
}

vector<pair<ll, int>> fatora(ll n) {
    vector<pair<ll, int>> res;

    for (ll i = 2; i * i <= n; i++) {
        int expoente = 0;
        while (n % i == 0) {
            n = n / i;
            expoente++;
        }
        res.pb({i, expoente});
    }
    if (n > 1) res.pb({n, 1});
    return res;
}

vector<pair<ll, int>> fatora2(ll n, vector<ll> &lp) {
    map<ll, int> fatores;

    while (n > 1) {
        fatores[lp[n]]++;
        n /= lp[n];
    }

    vector<pair<ll, int>> ans;
    for (auto &e : fatores) {
        ans.eb(e);
    }

    return ans;
}

bool primot(ll n) {
    bool ans = false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) {
                ans = true;
            }
            else {
                ans = false;
            }

            break;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    scanf("%d", &q);

    vector<ll> primos = crivo(1000000);
    for (int i = 0; i < q; i++) {
        ll x;
        scanf("%lld", &x);

        bool res = false;
        ll l = 0, r = primos.size()-1;
        while(l <= r) {
            ll mid = (l+r)/2;
            if (primos[mid]*primos[mid] == x) {
                res = true;
                break;
            } else if (primos[mid]*primos[mid] < x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (res) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }

    return 0;
}