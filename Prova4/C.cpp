#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ii pair<int, int>
#define ff first
#define ss second

#define PRIMO 1000000007

set<int> corte;
int n, a, b, c;
int v_min, v_max;
int tb[4001][4001];

int dp(int i, int valor) {
    if (valor > n) return 0;
    if (valor == n) return i;
    if (tb[i][valor] != -1) return tb[i][valor];

    int ans = 0;
    for (auto &e : corte) {
        ans = max(ans, dp(i+1, valor + e));
    }
    
    return tb[i][valor] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(tb, -1, sizeof(tb));

    cin >> n >> a >> b >> c;

    corte.emplace(a);
    corte.emplace(b);
    corte.emplace(c);

    int ans = dp(0, 0);

    cout << ans << endl;

    return 0;
}