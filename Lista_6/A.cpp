#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>

#define PRIMO 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,q;
    cin >> n >> m >> q;

    vector<ii> g(n+1);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        g[a].second++;
        g[b].first++;
    }

    for (int i = 0; i < q; i++) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            cout << g[x].second << endl;
        } else if (t == 2) {
            cout << g[x].first << endl;
        }
    }

    return 0;
}