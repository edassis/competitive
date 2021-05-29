#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" \
                  << "\n";
#else
#define W(x)
#endif

using namespace std;

#define vi  vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define ll  long long
#define pb  push_back
#define eb  emplace_back
#define mp  make_pair
#define ii  pair<int, int>
#define ff  first
#define ss  second

#define prime 1e9 + 7

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vi         v(n + 1);
    vector<vi> adj(n + 1);
    vii        custo(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];

        custo[i].ff = i;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        custo[x].ss += v[y];
        custo[y].ss += v[x];

        adj[x].eb(y);
        adj[y].eb(x);
    }

    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        vii pq;

        for (auto &e : custo)
            if (e.ff != 0) pq.eb(e);
        
        sort(pq.begin(), pq.end(), [](ii a, ii b) {
            return a.ss > b.ss;
        });

        int c = 0;
        int dt, u;
        while (pq.size() > 1) {
            tie(u, dt) = pq.back();
            pq.pop_back();

            for (auto &e : adj[u]) {
                pq[e].ss -= v[u];
            }

            c += dt;

            sort(pq.begin(), pq.end(), [](ii a, ii b) {
                return a.ss > b.ss;
            });
        }

        ans = min(ans, c);
    }

    cout << ans << endl;

    return 0;
}