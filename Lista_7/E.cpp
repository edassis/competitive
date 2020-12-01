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

const int N = 10000;
const ll oo = 1e18;

vector<vector<pair<ll, pair<ll, int>>> > g(N + 1);
vector<ll> d(N + 1, oo);
vector<int> precedence(N + 1, -1);
vector<ll> custo(N + 1, -1);

void dijkstra(int s) {
    priority_queue<pair<ll, pair<ll, int>>, vector<pair<ll, pair<ll, int>>>, greater<pair<ll, pair<ll, int>>> > pq;
    // for (int i = 0; i <= N; i++) d[i] = oo;

    d[s] = 0;
    custo[s] = 0;
    pq.emplace(d[s], make_pair(0, s));
    ll dt, w;
    int u, v;
    ll cv;
    while (pq.size()) {
        dt = pq.top().first;
        // cu = pq.top().second.first;
        u = pq.top().second.second;
        pq.pop();
        if (dt > d[u]) continue;
        ll custo_ant = 0;
        for (auto &edge : g[u]) {
            w = edge.first;
            cv = edge.second.first;
            v = edge.second.second;
            if (d[v] > d[u] + w || (d[v] == d[u] + w && cv < custo_ant)) {
                d[v] = d[u] + w;
                custo[v] = custo[u] + cv;
                precedence[v] = u;
                pq.emplace(d[v], make_pair(custo[v], v));
            }
            custo_ant = cv;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    int a,b,l,c;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> l >> c;

        g[a].eb(l, make_pair(c, b));
        g[b].eb(l, make_pair(c, a));
    }

    dijkstra(1);
    
    ll maior = custo[0];
    for (int i = 1; i <= n; i++) {
        if (maior < custo[i]) maior = custo[i];
    }

    cout << maior << endl;

    return 0;
}