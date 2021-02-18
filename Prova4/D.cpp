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

int n,p,k;
vector<ii> combo;
int tb[100][100];

int dp(int qtd, int custo, int nv) {
    if (qtd >= k) return custo;
    if (tb[qtd][nv] != -1) return tb[qtd][nv];

    int ans = 1e9;
    for (auto &e: combo) {
        ans = min(ans, dp(qtd+e.ff, custo+e.ss, nv+1));
    }

    return tb[qtd][nv] = ans;
}

// int inter_dp(int p) {
//     for (int i = 0; i <= n; i++) {
//         for (int j = 0; j <= p; j++) {
//             tb[i][j] = 0;
//         }
//     }

//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= p; j++) {
//             if (j >= peso[i]) {
//                 tb[i][j] = max(tb[i-1][j-peso[i]]+valor[i], tb[i-1][j]);
//             } else {
//                 tb[i][j] = tb[i-1][j];
//             }
//         }
//     }

//     return tb[n][p];
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(tb, -1, sizeof(tb));

    cin >> n >> p >> k;
    combo = vector<ii>(n);

    for (int i = 0; i < n; i++) {
        int q,v;
        cin >> q >> v;
        combo[i] = {q,v};
    }
    combo.pb({1, p});

    int ans = dp(0, 0, 0);
    cout << ans << endl;

    return 0;
}