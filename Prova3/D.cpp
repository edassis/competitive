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

const ll oo = 1e18;
const int N = 100;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, t;
    cin >> n >> m;

    ll G[n+1][n+1];
    ll D[n+1][n+1];
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        G[a][b] = 1;
        G[b][a] = 1;
    }
    cin >> s >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                D[i][j] = 0;
            else {
                if (G[i][j])
                    D[i][j] = G[i][j];
                else
                    D[i][j] = oo;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    
    ll tempo = 0;
    for (int i = 0; i < n; i++) {
        tempo = max(D[s][i] + D[i][t], tempo);
    }

    cout << tempo << endl;

    return 0;
}