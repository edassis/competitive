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

const int N = 250;
const ll oo = 1e18;

vector<vector<pair<ll, int>>> g(N + 1);
vector<ll> d(N + 1, oo);

void dijkstra(int s, int c) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 0; i <= N; i++) d[i] = oo;

    d[s] = 0;
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
                if ( (v == u + 1) || u >= c) {
                    d[v] = d[u] + w;
                    pq.emplace(d[v], v);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, c, k;
    cin >> n >> m >> c >> k;

    for (int i = 0; i < m; i++) {
        int u, v, p;
        cin >> u >> v >> p;

        g[u].eb(p, v);
        g[v].eb(p, u);
    }

    dijkstra(k, c);

    cout << d[c] << endl;

    return 0;
}