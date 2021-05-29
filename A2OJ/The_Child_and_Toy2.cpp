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

#define prime 1000000007

int tb[1005][1005];
int visitado[1005];

int f(vector<vi> &g, vi &custo, vi &v, int no, size_t qtd, int value) {
    if (qtd == g.size() - 3) return value;
    if (visitado[no]) return prime;

    if (tb[no][qtd]) return tb[no][qtd];

    visitado[no] = true;

    int ans = 1e9;

    for (auto &e : g[no]) {
        custo[e] -= v[no];
    }

    for (auto &e : g[no]) {
        ans = min(ans, f(g, custo, v, e, qtd+1, value+custo[no]));
    }

    for (auto &e : g[no]) {
        custo[e] += v[no];
    }

    return tb[no][qtd] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vi         v(n + 1);
    vector<vi> adj(n + 1);
    vi         custo(n + 1);

    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        custo[x] += v[y];
        custo[y] += v[x];

        adj[x].eb(y);
        adj[y].eb(x);
    }

    int ans = prime;
    for (int i = 1; i <= n; i++) {
        memset(tb, 0, sizeof(tb));
        memset(visitado, 0, sizeof(visitado));
        
        ans = min(ans, f(adj, custo, v, i, 0, 0));
    }

    cout << ans << endl;

    return 0;
}