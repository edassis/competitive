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

int n, x;
int moeda[1001];
int tb[1001];

int dp(int a) {
    if (tb[a] != -1) return tb[a];

    if (a == 0) return 0;

    int nv = 1e9;
    for (int i = 0; i < n; i++) {
        if (a - moeda[i] >= 0) {
            nv = min(nv, dp(a-moeda[i])+1);
        }
    }

    return tb[a] = nv;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(tb, -1, sizeof(tb));

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> moeda[i];
    }
    int ans = dp(x);

    cout << ans << endl;

    return 0;
}