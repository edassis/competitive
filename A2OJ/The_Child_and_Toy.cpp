#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
#else
    #define W(x)
#endif

using namespace std;

#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>
#define ff first
#define ss second

#define prime 1000000007

void update(vector<vii> &g, int no, int value) {
    // int ans = 0;
    
    for (auto &e : g[no]) {
        e.ff += value;
    }

    // return ans;
}

int dijkstra(vector<vii> &adj, int start) {
    priority_queue<ii, vii, greater<vi> > pq;
    vi d(adj.size());

    for (auto &e : d) e = prime;

    d[start] = 0;
    pq.emplace(check(start), start);

    int dt, w;
    int u, v;
    while(pq.size()) {
        tie(dt, u) = pq.top(); pq.pop();
        update(adj, u, -dt);        // vai afetar os outros caminhos.
                                    // vai executar mais de uma vez para o mesmo no.

        if(dt > d[u]) continue;
        
        for(auto &e : adj[u]) {
            tie(w, v) = e;
            if(d[v] > w + d[u]) {

                d[v] = w + d[u];
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

    vi v(n+1);
    vector<vi> adj(n+1);

    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;

        custo[x] += v[y];
        custo[x] += v[y];
        adj[x].eb(y, v[y]);
        adj[y].eb(x, v[x]);
    }

    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, f(adj, i));
    }

    cout << ans << endl;

    return 0;
}