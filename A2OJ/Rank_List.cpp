#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" \
                  << "\n";
#else
#define W(x)
#endif

using namespace std;

#define vi  vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define ll  long long
#define pb  push_back
#define eb  emplace_back
#define mp  make_pair
#define ii  pair<int, int>
#define ff  first
#define ss  second

#define prime 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vii tab;
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int p, t;
        cin >> p >> t;

        tab.eb(p, t);
    }

    sort(tab.begin(), tab.end(), [](ii a, ii b) {
        return a.ff > b.ff || (a.ff == b.ff && a.ss < b.ss);
    });

    int ct = 0;
    for (int i = 0; i < n; i++) {
        if (tab[i] == tab[k-1]) ct++;
    }

    cout << ct << endl;

    return 0;
}