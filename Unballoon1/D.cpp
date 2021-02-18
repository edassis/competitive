#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int,int>
#define ff first
#define ss second

#define PRIMO 1000000007

bool bfs(vector<vi> &grafo, int a, int b) {
    vector<bool> visitado(grafo.size(), false);
    queue<int> q;
    q.emplace(a);

    while(q.size()) {
        int no = q.front(); q.pop();

        if (!visitado[no]) {
            if (no == b) return true;
            visitado[a] = true;
            
            for (auto &filho : grafo[no]) {
                q.emplace(filho);
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<vi> lista_contatos(n+1);
    vector<vector<bool>> access(n+1, vector<bool>(n+1, false));
    
    for (int i = 0 ; i < q; i++) {
        int tp, a, b;
        cin >> tp >> a >> b;
        if (tp == 1) {
            lista_contatos[a].eb(b);
            lista_contatos[b].eb(a);
            access[a][b] = true;
            for (int j = 1; j < n+1; j++) {
                if (a == j) continue;
                if (!access[a][j] and bfs(lista_contatos, a, j)) access[a][j] = true;
            }
        } else {
            if (access[a][b]) cout << "SIM" << '\n';
            else cout << "NAO" << '\n';
        }
    }
    cout << endl;
    
    return 0;
}