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

const ll oo = 1e18;

void dijkstra(char s, map<char, map<char, ll>> &g, map<char, ll> &d) {
    priority_queue<pair<ll, char>, vector<pair<ll, char>>, greater<pair<ll, char>> > pq;
    
    d[s] = 0;
    pq.emplace(d[s], s);
    ll dt, w;
    char u, v;
    while(pq.size()) {
        tie(dt, u) = pq.top(); pq.pop();
        if (dt > d[u]) continue;
        for(auto &edge : g[u]) {
            tie(v, w) = edge;
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

    int n;
    cin >> n;

    map<char, map<char, ll> > go;
    map<char, map<char, ll> > gt;
    map<char, ll> dst_o;
    map<char, ll> dst_t;
    
    for (int i = 0; i < n; i++) {
        char taxi, dir, a, b;
        int w;
        cin >> taxi >> dir >> a >> b >> w;

        if (taxi == 'O') {
            go[a][b] = w;
            if (dir == 'B') go[b][a] = w;
            dst_o[a] = oo;
            dst_o[b] = oo;
        } else {
            gt[a][b] = w;
            if (dir == 'B') gt[b][a] = w;
            dst_t[a] = oo;
            dst_t[b] = oo;
        }
    }
    char s1, s2;
    cin >> s1 >> s2;

    dijkstra(s1, go, dst_o);
    dijkstra(s2, gt, dst_t);

    vector<ll> custo;
    vector<char> esquina;
    for (auto &e : dst_o) {
        if (e.second < oo && dst_t.count(e.first) && dst_t[e.first] < oo) {
            esquina.eb(e.first);
            custo.eb(dst_t[e.first] + e.second);
        }
    }

    if (custo.size()) {
        sort(custo.begin(), custo.end());
        cout << custo.front() << endl;

        for (auto &e : esquina) {
            cout << e << ' ';
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}