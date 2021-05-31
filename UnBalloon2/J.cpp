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

#define prime 1e9+7

const int N = 1e5;
const ll oo = 1e18;

// vector<vector<pair<ll, int>>> g(N+1);
// vector<vector<int>> g(N+1);
// ll d[N+1];

void dijkstra(vector<vector<pair<ll, int>>>& g, ll d[], int s, int n) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > pq;

    for (int i = 0; i <= n; i++) {
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin >> n >> m;
    int s,t,k; cin >> s >> t >> k;
    
    vi pontos(k);
    
    vector<vector<pair<ll, int>>> g(n+1);       // weight, v
    ll d[n+1];  // dijkstra -> oo

    for(int i = 0; i < k; i++) cin >> pontos[i];

    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        g[u].eb(w, v);
        g[v].eb(w, u);
    }

    dijkstra(g, d, s, n);
    
    ll ref_dist = d[t];
    W(ref_dist);

    ll interesse_dist = 0;
    for(int i = 0; i <= n; i++) {
        if(i == s || i == t) continue;

        vector<vector<pair<ll, int>>> g2(n+1);
        ll d2[n+1];
        dijkstra(g2, d2, i, n);

        interesse_dist += d[i] + d2[t];
        W(interesse_dist);
    }

    if(interesse_dist <= ref_dist) cout << "Sim" << endl;
    else cout << "Nao" << endl;

    return 0;
}