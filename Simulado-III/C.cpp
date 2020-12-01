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

#define N 100001

int visitados[N] = {0};
// int n;

int bfs(int o, int d) {
    queue<ii> fila;
    fila.emplace(o, 0);

    int canal, cliques;

    while (fila.size()) {
        tie(canal, cliques) = fila.front(); fila.pop();

        if (canal == d) return cliques;

        if (canal * 3 <= 100000) {
            if (visitados[canal * 3] == 0) {
                visitados[canal * 3] = 1;
                fila.emplace(canal * 3, cliques + 1);
            }
        }

        if (canal * 2 <= 100000) {
            if (visitados[canal * 2] == 0) {
                visitados[canal * 2] = 1;
                fila.emplace(canal * 2, cliques + 1);
            }
        }

        if (canal + 1 <= 100000) {
            if (visitados[canal + 1] == 0) {
                visitados[canal + 1] = 1;
                fila.emplace(canal + 1, cliques + 1);
            }
        }

        if (canal - 1 > 0) {
            if (visitados[canal - 1] == 0) {
                visitados[canal - 1] = 1;
                fila.emplace(canal - 1, cliques + 1);
            }
        }

        if (canal % 2 == 0) {
            if (visitados[canal / 2] == 0) {
                visitados[canal / 2] = 1;
                fila.emplace(canal / 2, cliques + 1);
            }
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int o, d;
    int k;
    cin >> o >> d >> k;
    set<int> proib;

    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;

        visitados[c] = -1;
    }

    int cliques = bfs(o, d);

    cout << cliques << endl;

    return 0;
}