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

const int N = 100000;
const ll oo = 1e18;

vector<vector<pair<ll, int>>> g(N+1);
// vector<vector<int>> g(N+1);
ll d[N+1];

// bool visitado[N+1];

void dijkstra(int s) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > pq;

    for (int i = 0; i <= N; i++) {
        d[i] = oo;
    }

    d[s] = 0;
    pq.emplace(d[s], s);

    ll dt, w;
    int u, v;
    while (pq.size()) {
        tie(dt, u) = pq.top(); pq.pop();
        if (dt > d[u]) continue;
        for (auto &e : g[u]) {
            tie(w, v) = e;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.emplace(d[v], v);
            }
        }
    }
}

/* void bfs(int s) {
    for (int i = 0; i <= N; i++) {
        visitado[i] = false;
    }
    queue<int> q;
    q.emplace(s);
    while(q.size()) {
        int vertex = q.front(); q.pop();
        visitado[vertex] = true;
        
        for (auto &e : g[vertex]) {
            q.emplace(e);
        }
    }
} */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k,q;
    cin >> n >> m >> k >> q;

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;

        g[a].eb(1, b);
        g[b].eb(1, a);
    }

    dijkstra(k);

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        if (d[x] != oo) {
            cout << d[x] << endl;
        } else {
            cout << "infinito" << endl;
        }
    }

    return 0;
}