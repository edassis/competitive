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

#define N 101
const ll oo = 1e18;

ll D[N][N], G[N][N];

vector<vector<pair<ll, int>>> g(N);
ll d[N];
vector<int> predecessor(N);

void dijkstra_greatest(int start) {
    
    for (int i = 0; i < N; i++) {
        d[i] = 0;
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>,
            less<pair<ll, int>> > pq;
    
    pq.emplace(oo, start);

    ll dt, w;
    int u, v;
    while(pq.size()) {
        tie(dt, u) = pq.top(); pq.pop();
        if (dt < d[u]) continue;
        for (auto edge : g[u]) {
            tie(w, v) = edge;

            if (d[v] < d[u] + w) {
                d[v] = d[u] + w;
                predecessor[v] = u;
                pq.emplace(d[v], v);
            }
        }
    }
}

void floyd_warshall(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) D[i][j] = 0;
            else {
                if (G[i][j]) D[i][j] = G[i][j];
                else D[i][j] = -oo;
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                D[i][j] = max(D[i][j], min(D[i][k],  D[k][j]));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int s, d, t;
    cin >> s >> d >> t;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // g[u].emplace_back(w, v);
        // g[v].emplace_back(w, u);
        G[u][v] = w-1;
        G[v][u] = w-1;
    }

    // dijkstra_greatest(s);
    floyd_warshall(n);

    int res = ceil((double) (t) / (double) D[s][d]);

    cout << res << endl;

    return 0;
}