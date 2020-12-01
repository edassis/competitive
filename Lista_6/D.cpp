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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,t;
    cin >> n >> t;

    vector<vector<int>> g(n+1);
    vector<bool> visitado(n+1, false);

    for (int i = 1; i <= n - 1; i++) {
        int a;
        cin >> a;

        g[i].eb(i + a);
    }

    // bfs
    queue<int> q;
    q.push(1);
    while (q.size()) {
        int u = q.front(); q.pop();
        visitado[u] = true;
        for (auto &e : g[u]) {
            if (!visitado[e]) {
                q.push(e);
            }
        }
    }

    if (visitado[t]) cout << "sim" << endl;
    else cout << "nao" << endl;
    
    return 0;
}