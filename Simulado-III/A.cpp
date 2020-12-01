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

const int N = 100005;
const ll oo = 1e18;

// ll d[N];
// vll precedence;

vector<vector<int>> g;
vector<bool> init_visited;
vector<bool> cur_visited;

// void dijkstra(int start) {

// }

void dfs(int vertex, int ignore, vector<bool> &visited) {
    if (vertex != ignore)
        visited[vertex] = true;
    else
        return;

    for (int w : g[vertex]) {
        if (!visited[w]) {
            dfs(w, ignore, visited);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    g = vector<vector<int>>(n+1);
    init_visited = vector<bool>(n+1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back({b});
    }

    dfs(1, 0, init_visited);

    for (int i = 0; i < q; i++) {
        cur_visited = vector<bool>(n+1, false);

        int u, v;
        cin >> u >> v;

        dfs(1, v, cur_visited);
        
        if (cur_visited[u] == init_visited[u] && u != 1) {
            cout << "nao" << endl;
        } else {
            cout << "sim" << endl;
        }
    }
    return 0;
}