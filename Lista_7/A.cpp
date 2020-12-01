#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int, int>

#define PRIMO 1000000007

const ll oo = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, q;
    cin >> n >> m >> s >> q;

    vector<vector<pair<ll, int>>> g(n + 1);
    vector<ll> d(n + 1, oo);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        
        g[a].eb(w, b);
        g[b].eb(w, a);
    }

    d[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(d[s], s);
    ll dt, w;
    int u, v;
    while (pq.size()) {
        tie(dt, u) = pq.top();
        pq.pop();
        if (dt > d[u]) continue;
        for (auto &edge : g[u]) {
            tie(w, v) = edge;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.emplace(d[v], v);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        cout << d[x] << endl;
    }
    return 0;
}