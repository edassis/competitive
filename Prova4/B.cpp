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

int n, k;
vi peso(101), valor(101);
int tb[101][10001];

int dp(int i, int p) {
    if (i > n || p == 0) return 0;
    if (tb[i][p] != -1) return tb[i][p];

    int pegar = 0;
    if (p >= peso[i]) {
        pegar = valor[i] + dp(i + 1, p - peso[i]);
    }
    int npegar = dp(i + 1, p);
    tb[i][p] = max(pegar, npegar);

    return tb[i][p];
}

int inter_dp(int p) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= p; j++) {
            tb[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= p; j++) {
            if (j >= peso[i]) {
                tb[i][j] = max(tb[i-1][j-peso[i]]+valor[i], tb[i-1][j]);
            } else {
                tb[i][j] = tb[i-1][j];
            }
        }
    }

    return tb[n][p];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(tb, -1, sizeof(tb));

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> valor[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> peso[i];
    }


    int ans = inter_dp(k);
    cout << ans << endl;

    return 0;
}