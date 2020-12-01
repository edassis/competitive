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

    set<int> validos;
    validos.emplace(1);
    
    int c, v;
    cin >> c >> v;
    vector<vector<ii>> grafo(c+1);

    for (int i = 0; i < v; i++) {
        int c1, c2, temp;
        cin >> c1 >> c2 >> temp;

        grafo[c1].eb(make_pair(c2, temp));
        grafo[c2].eb(make_pair(c1, temp));
    }

    queue<int> q;
    q.push(1);

    vector<bool> visited(c+1, false);
    visited[1] = true;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto &w : grafo[u]) {
            if (not visited[w.first] && w.second >= 0) {
                q.push(w.first);
                visited[w.first] = true;
            }
        }
    }

    int count = 0;
    for (auto e : visited) {
        if (e) count++;
    }

    cout << c - count << endl;

    return 0;
}