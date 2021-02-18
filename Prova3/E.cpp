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

const int N = 3000;

vector<vector<int>> g(N + 1);
vector<bool> visited(N + 1, false);

vector<int> qtd(N + 1);

// void bfs(int s) {
//     visited[s] = true;
//     vi nv(N+1, 0);
//     queue<int> q;
//     q.push(s);

//     while(q.size()) {
//         int u = q.front(); q.pop();

//         if (nv[u] == 2) break;

//         for (auto &edge : g[u]) {

//             if (!visited[edge]) {
//                 nv[edge] = nv[u] + 1;
//                 visited[edge] = true;
//                 q.push(edge);
//             }
//             if (nv[edge] == 2)
//                 qtd[edge]++;
//         }
//     }
// }

void dfs(int s, int nv) {
    visited[s] = true;

    if (nv == 2) {
        return;
    }

    for (int e : g[s]) {
        if (nv == 1) {
            qtd[e]++;
        }
        
        if (!visited[e]) {
            nv++;
            dfs(e, nv);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a].eb(b);
    }

    for (auto &e : qtd) e = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            visited[j] = false;
        }
        dfs(i, 0);
    }

    // for (int i = 1; i <= n; i++) {
    //     for (auto &e : g[i]) {
    //         for (auto &e2 : g[e]) {
    //             qtd[e2]++;
    //         }
    //     }
    // }

    int los = 0;
    for (int i = 1; i <= n; i++) {
        if (qtd[i]) los += qtd[i] - 1;
    }

    cout << los << endl;

    return 0;
}