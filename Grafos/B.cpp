// B. Pedágio
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, e, l, p;
    cin >> c >> e >> l >> p;

    vector<vi> grafo(c + 1);

    for (int i = 0; i < e; i++) {
        int c1, c2;
        cin >> c1 >> c2;

        grafo[c1].eb(c2);
        grafo[c2].eb(c1);
    }

    queue<int> q;
    q.push(l);
    
    vector<bool> visited(c + 1, false);
    visited[l] = true;
    
    vi res;
    int nivel = 0;
    while (q.size() && nivel <= p) {
        int u = q.front();
        q.pop();
        for (auto &e : grafo[u]) {
            if (not visited[e]) {
                q.push(e);
                visited[e] = true;

                res.eb(e);
            }
        }
        nivel++;
    }

    sort(res.begin(), res.end());

    for(auto &e : res) {
        cout << e << ' ';
    }
    cout << endl;

    return 0;
}