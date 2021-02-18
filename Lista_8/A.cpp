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

int w, n;
vi peso(1001), valor(1001);
int tb[1001][1001];

int dp(int i, int p) {
    if (i == n || p == 0) return 0;
    if (tb[i][p] != -1) return tb[i][p];

    int pegar = 0;
    if (p >= peso[i]) {
        pegar = valor[i] + dp(i + 1, p - peso[i]);
    }
    int npegar = dp(i + 1, p);
    tb[i][p] = max(pegar, npegar);

    return tb[i][p];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(tb, -1, sizeof(tb));

    cin >> w >> n;

    for (int i = 0; i < n; i++) {
        cin >> peso[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> valor[i];
    }

    int ans = 0;
    ans = max(ans, dp(0, w));

    cout << ans << endl;

    return 0;
}