#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>
#define ff first
#define ss second

#define PRIMO 1000000007

vi merge(vi &a, vi &b) {
    unsigned i = 0, j = 0;
    vi c;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            c.eb(a[i]);
            i++;
        } else {
            c.eb(b[j]);
            j++;
        }
    }

    while (i < a.size()) {
        c.eb(a[i++]);
    }

    while (j < b.size()) {
        c.eb(b[j++]);
    }

    return c;
}

vi mergesort(vi &a) {
    if (a.size() == 1) return a;
    
    vi l(a.begin(), a.begin() + (a.size()/2) );
    vi r(a.begin() + (a.size()/2), a.end() );

    l = mergesort(l);
    r = mergesort(r);

    a = merge(l, r);
    
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a;
    int t;

    while (cin >> t) a.eb(t);

    a = mergesort(a);

    for (auto &e: a) cout << e << ' ';
    cout << endl;

    return 0;
}