#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>

bool bro(ll n, ll m) {
    vector<pair<ll, int>> expn;
    ll auxn = n;
    for (ll x = 2; x*x <= n; x++) {
        int exp = 0;
        while (auxn % x == 0) {
            auxn /= x;
            exp++;
        }
        if (x != n && x != m && exp)
            expn.pb({x, exp});   
    }
    if (auxn > 1 && auxn != n && auxn != m) expn.pb({auxn, 1});

    vector<pair<ll, int>> expm;
    ll auxm = m;
    for (ll x = 2; x*x <= m; x++) {
        int exp = 0;
        while (auxm % x == 0) {
            auxm /= x;
            exp++;
        }
        if (x != n && x != m && exp)
            expm.pb({x, exp});   
    }
    if (auxm > 1 && auxm != n && auxm != m) expm.pb({auxm, 1});

    bool ans = false;
    unsigned pos = expn.size() >= expm.size() ? expm.size() : expn.size();
    
    for (unsigned i = 0; i < pos; i++) {
        ans = true;
        if (expm[i].first != expn[i].first) {
            ans = false;
            break;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    scanf("%lld %lld", &n, &m);

    bool ans = bro(n,m);
    if (ans){
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }
    return 0;
}