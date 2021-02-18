#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int, int>
#define first ff
#define second ss

#define PRIMO 1000000007

const ll oo = 1e18;
const int N = 100000;

vector<vector<pair<ll, int>>> g(N + 1);
ll d[N + 1];

// ll G[N+1][N+1];
// ll D[N+1][N+1];

void dijkstra(int s, int t) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (auto &e : d) e = oo;

    d[s] = 0;
    pq.emplace(d[s], s);
    ll dt, w;
    int u, v;
    // int tmp;
    while (pq.size()) {
        // dt = pq.top().ff;
        // tie(u, tmp) = pq.top().ss;
        tie(dt, u) = pq.top();
        pq.pop();
        
        if (dt > d[u] || dt > t) continue;
        
        for (auto &edge : g[u]) {
            tie(w, v) = edge;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.emplace(d[v], v);
            }
        }
    }
}

// void floyd_warshall(int n) {
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             if (i == j) D[i][j] = 0;
//             else {
//                 if (G[i][j]) D[i][j] = G[i][j];
//                 else D[i][j] = oo;
//             }
//         }
//     }

//     for (int k = 1; k <= n; k++) {
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= n; j++) {
//                 D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
//             }
//         }
//     }
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s;
    ll t;
    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        g[b].eb(w, a);
    }

    // floyd_warshall(n);
    int qtd = 0;
    dijkstra(s, t);    
    for (int i = 0; i < n; i++) {
        if (d[i] <= t) qtd++;
    }

    cout << qtd << endl;

    return 0;
}