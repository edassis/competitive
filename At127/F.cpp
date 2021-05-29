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

struct Mediana {
    multiset<int> l, r;
    ll lsoma = 0;
    ll rsoma = 0;

    void add(int value) {
        if (r.size() && value >= *r.begin()) {
            r.emplace(value);
            rsoma += value;
        }
        else {
            l.emplace(value);
            lsoma += value;
        }
        balance();
    }

    int query() {
        return *l.rbegin();
    }

    void balance() {
        while(r.size() > l.size()) {
            auto it = r.begin();
            lsoma += *it;
            rsoma -= *it;
            l.emplace(*it);
            r.erase(it);
        }

        while(l.size() > r.size()+1) {
            auto it = prev(l.end());
            rsoma += *it;
            lsoma -= *it;
            r.emplace(*it);
            l.erase(it);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    Mediana m;
    ll bc = 0;
    while(q--) {
        int t; cin >> t;

        if(t == 1) {
            int a, b; cin >> a >> b;     
            m.add(a);
            bc += b;
        }
        else {
            ll med = m.query();
            ll l = m.lsoma - med;
            ll r = m.rsoma;
            l = l - med*(m.l.size()-1);
            r = r - med*m.r.size();
            ll fx = abs(l) + abs(r) + bc;
            cout << med << ' ' << fx << endl;
        }
    }

    return 0;
}