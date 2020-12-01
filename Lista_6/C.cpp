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

    int n,m;
    cin >> n >> m;

    vector<vector<char>> g(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            
            g[i].eb(c);
        }
    }

    vector<ii> pontos;
    queue<ii> q;
    vector<vector<bool>> visitado(n);
    for (auto &e : visitado) e = vector<bool> (m, false);

    q.emplace(1, 1);
    while (q.size()) {
        auto p = q.front(); q.pop();
        visitado[p.first][p.second];

        if (p.first > 1) {
            if (visitado[p.first-1][p.second]) {
                
            }
        }
    }

    return 0;
}