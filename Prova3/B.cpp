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
const int N = 20000;

vector<vector<pair<ll, int>>> g(N + 1);
ll d[N + 1];

void dijkstra(int s) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (auto &e : d) e = oo;

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
                d[v] = d[u] + w;
                pq.emplace(d[v], v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        g[a].eb(w, b);
        g[b].eb(w, a);
    }

    dijkstra(s);

    if (d[t] != oo) {
        cout << d[t] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}