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

const int N = 100000;
const ll oo = 1e18;

vector<vector<pair<ll, int>>> g(N + 1);
ll d[N + 1];

vector<map<int, int>> arrives(N + 1);

void dijkstra(int s, int n) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 1; i <= N; i++) {
        d[i] = oo;
    }

    d[s] = 0;
    pq.emplace(d[s], s);

    ll dt, w;
    int u, v;
    while (pq.size()) {
        tie(dt, u) = pq.top();
        pq.pop();

        if (dt > d[u]) continue;

        if (u != n) {
            auto it = arrives[u].upper_bound(dt);
            auto it_last = prev(arrives[u].end(), 1);
            if (it == arrives[u].begin() || it == it_last) {

            } else {
                d[u] = it->second;
            }
        }

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

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        g[a].emplace_back(c, b);
        g[b].emplace_back(c, a);
    }

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;

        vector<ll> times(k);
        for (int j = 0; j < k; j++) {
            cin >> times[j];
        }

        int aux = 0;
        for (int j = 0; j < k; j++) {
            if (aux < times[j]) {
                arrives[i][aux] = times[j] - 1;
            }
            aux = times[j] + 1;
        }
        arrives[i][aux] = aux;
    }

    dijkstra(1, n);

    if (d[n] != oo)
        cout << d[n] << endl;
    else
        cout << -1 << endl;

    return 0;
}