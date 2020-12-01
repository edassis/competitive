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


const int N = 1002;
const ll oo = 1e18;

vector<vector<pair<ll, int>>> g(N);
int predecessor[N];

ll d[N];

void dijkstra(int start) {
    for (int i = 0; i < N; i++) {
        d[i] = oo;
    }

    d[start] = 0;
    predecessor[start] = start;
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(d[start], start);

    ll dt, w;
    int u, v;
    while (pq.size()) {
        tie(dt, u) = pq.top(); pq.pop();

        if (dt > d[u]) continue;
        
        for (auto &edge : g[u]) {
            tie(w, v) = edge;
            
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                predecessor[v] = u;
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
        int s, t, b;
        cin >> s >> t >> b;

        g[s].emplace_back(b, t);
        g[t].emplace_back(b, s);
    }

    dijkstra(0);

    // for (int i = 0; i <= n + 1; i++) {
    //     cout << "min dist " << 0 << " - " << i << " = " << d[i] << endl;
    //     cout << "predecessor de " << i << " = " << predecessor[i] << endl;
    // }
    
    cout << d[n+1] << endl;

    return 0;
}